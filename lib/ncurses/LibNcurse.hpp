/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** LibNcurse
*/

#ifndef TEK2_LIBNCURSE_HPP
#define TEK2_LIBNCURSE_HPP

#include "../IGraphics.hpp"

class LibNcurse : public IGraphics {
    public:
        LibNcurse();
        ~LibNcurse();

    public:
        void Init();
        void drawRectangle(const Rectangle<int> &rect, const std::string &color) final;
        void drawWindow() final;
        const std::string handleEvent() final;
        void loadTextures(std::vector<std::string>) final;
        std::string getString();
        void enterTextMode();
        const int getColor(std::string) const;
        void drawText(const std::string &str, const Vector2<int> &position, const std::string &color) final;
        void clearWindow() final;
        void close() final;
        const bool isOpen() const final;

    private:
        bool _textMode;
        WINDOW *_win;
        std::string _input;
    Color _color = Color(2, 0, 0, 0);
};

#endif //TEK2_LIBNCURSE_HPP
