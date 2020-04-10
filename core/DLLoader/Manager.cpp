/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Manager
*/

#include "Manager.hpp"

/**
 * @brief Manager constructor
 * 
 * Initialize core manager.
 * Load all graphical libraries from lib/ folder
 * Initialize the @par defaultLib
 * 
 * @return New instance of Manager
 */
Manager::Manager(const std::string &defaultLib) :
_launched(false), _currentLib(GetLibraryName(defaultLib)),
_posSize(0, 0, 0, 0), _launcher(std::make_unique<Launcher>())
{
    this->_gameCore = nullptr;
    this->_libraries.insert({this->_currentLib, std::make_unique<DLLoader<IGraphics> >(defaultLib)});
    for (const auto &file : std::filesystem::directory_iterator("lib/")) {
        std::string path = std::string(file.path());
        std::string lib = GetLibraryName(path);
        if (lib != this->_currentLib && this->IsLibrary(lib))
            this->_libraries.insert({lib, std::make_unique<DLLoader<IGraphics>>(path)});
    }
    this->GetInstance().Init();
}

Manager::~Manager()
{
    this->_libraries.clear();
}

/**
 * @brief Get the instance of the current graphical library
 * 
 * If `GetInstance()` from DLLoader fail, an ArcadeException is thrown and the program exit.
 * 
 * @return A reference to a graphical library
 */
IGraphics &Manager::GetInstance(void)
{
    try
    {
        return (_libraries[this->_currentLib]->GetInstance());
    }
    catch (const ArcadeException& ex)
    {
        std::cerr << "[" << ex.GetComponent() << "] " << ex.what() << std::endl;
        std::exit(84);
    }
}

void Manager::ChangeLibrary(const std::string &newLib)
{
    this->GetInstance().close();
    auto it = this->_libraries.find(this->_currentLib);

    if (newLib.compare("next") == 0) {
        if ((++it) == this->_libraries.end())
            it = this->_libraries.begin();
        this->_currentLib = it->first;
        this->GetInstance().Init();
        std::cout << "->[" << it->first << "]<-" << std::endl;
        this->LoadTextures();
    } else if (newLib.compare("prev") == 0) {
        if (it == this->_libraries.begin()) {
            it = (this->_libraries.end());
            std::cout << "set to end" << std::endl;
        }
        --it;
        this->_currentLib = it->first;
        this->GetInstance().Init();
        std::cout << "->[" << it->first << "]<-" << std::endl;
        this->LoadTextures();
    }
    std::cout << "lib changed" << std::endl;
}

/**
 * @brief Extract library name from path
 * 
 * @param str Library path
 * 
 * @return Name of library
 */
const std::string Manager::GetLibraryName(const std::string &path) const
{
    std::string lname = path.substr(path.find('/') + 1, path.length());

    if (this->IsLibrary(lname))
        return (lname);
    return ("");
}

/**
 * @brief Check if the file is a .so library
 * 
 * @param file Library filename with extension
 * 
 * @return True if it is a library, false otherwise
 */
bool Manager::IsLibrary(const std::string &file) const
{
    if (file.substr(file.find_last_of(".") + 1) == "so")
        return (true);
    return (false);
}

/**
 * @brief Load texures of the loaded game
 */
void Manager::LoadTextures(void)
{
    if (_launched)
        this->GetInstance().loadTextures(this->_gameCore->getTextures());
}

void Manager::updateScore(std::string score)
{
    std::fstream scorefile;
    scorefile.open("score.txt", std::fstream::in | std::fstream::out | std::fstream::app);
    if (scorefile.is_open())
    {
        scorefile << this->_gameCore->getName() << " | " << _username << " | " << score << std::endl;
        scorefile.close();
    }
    else std::cout << "Unable to open file";
}

/**
 * @brief Execute game's instruction
 * Get instruction from the game, parse and execute
 */
void Manager::ExecuteInstructions(void)
{
    this->_instructions.clear();
    this->_event = this->GetInstance().handleEvent();
    if (this->_event == "exit" || !this->GetInstance().isOpen())
        return;
    else if (this->_event.compare("next") == 0 || this->_event.compare("prev") == 0) {
        this->ChangeLibrary(this->_event);
        return;
    }
    if (this->_event.find("text: ") < this->_event.length()) {
        this->_username = this->_event.substr(6);
        this->_instructions = _launcher->getInstructions("e");
    } else if (!this->_launched)
        this->_instructions = _launcher->getInstructions(this->_event);
    else
        this->_instructions = this->_gameCore->getInstruction(this->_event);
    for (auto &inst : this->_instructions) { // parse and execute instructions
        this->_instructionType = inst.substr(0, inst.find(' '));
        inst = inst.substr(inst.find(' ') + 1, inst.length());
        if (this->_instructionType == "load") {
            this->_gameCore = std::make_unique<GameModule>(inst);
            this->_launched = true;
            this->LoadTextures();
            return;
        } else if (this->_instructionType == "getstr") {
            this->GetInstance().enterTextMode();
            continue;
        } else if (this->_instructionType == "score")
            updateScore(inst);
        else if (this->_instructionType == "text") {
            inst = inst.substr(inst.find("'") + 1, inst.length());
            this->_textToWrite = inst.substr(0, inst.find("'"));
            inst = inst.substr(inst.find("'") + 2, inst.length());
        }
        this->_posSize.p1 = stoi(inst.substr(0, inst.find(' ')));
        inst = inst.substr(inst.find(' ') + 1, inst.length());
        this->_posSize.p2 = stoi(inst.substr(0, inst.find(' ')));
        inst = inst.substr(inst.find(' ') + 1, inst.length());
        if (this->_instructionType == "rectangle") {
            this->_posSize.p3 = stoi(inst.substr(0, inst.find(' ')));
            inst = inst.substr(inst.find(' ') + 1, inst.length());
            this->_posSize.p4 = stoi(inst.substr(0, inst.find(' ')));
            inst = inst.substr(inst.find(' ') + 1, inst.length());
            this->GetInstance().drawRectangle(this->_posSize, inst);
        } else
            this->GetInstance().drawText(this->_textToWrite, \
            {this->_posSize.p1, this->_posSize.p2}, inst);
    }
}