//
// Created by User on 5/19/2026.
//
#ifndef UNTITLED3_COLORS_H
#define UNTITLED3_COLORS_H


enum Color
{
    _BLACK = 1,
    _RED,
    _GREEN,
    _YELLOW,
    _BLUE,
    _MAGENTA,
    _CYAN,
    _WHITE
};

enum Text
{
    _BOLD = 1,
    _DIM,
    _ITALIC,
    _UNDERLINE,
    _BLINK,
    _REVERSE,
    _HIDDEN
};

#define BLACK           "\033[30m"
#define RED             "\033[31m"
#define GREEN           "\033[32m"
#define YELLOW          "\033[33m"
#define BLUE            "\033[34m"
#define MAGENTA         "\033[35m"
#define CYAN            "\033[36m"
#define WHITE           "\033[37m"

// ===== BRIGHT TEXT COLORS =====
#define BRIGHT_BLACK    "\033[90m"
#define BRIGHT_RED      "\033[91m"
#define BRIGHT_GREEN    "\033[92m"
#define BRIGHT_YELLOW   "\033[93m"
#define BRIGHT_BLUE     "\033[94m"
#define BRIGHT_MAGENTA  "\033[95m"
#define BRIGHT_CYAN     "\033[96m"
#define BRIGHT_WHITE    "\033[97m"

// ===== TEXT STYLES =====
#define BOLD            "\033[1m"
#define DIM             "\033[2m"
#define ITALIC          "\033[3m"
#define UNDERLINE       "\033[4m"
#define BLINK           "\033[5m"
#define REVERSE         "\033[7m"
#define HIDDEN          "\033[8m"

// ===== RESET =====
#define RESET           "\033[0m"

inline void font_table()
{
    cout <<
        "1. " << BOLD << "BOLD - жирный текст" << RESET << '\n' <<
        "2. " << DIM << "DIM - тусклый текст" << RESET << '\n' <<
        "3. " << ITALIC << "ITALIC - курсив" << RESET << '\n' <<
        "4. " << UNDERLINE << "UNDERLINE - подчеркнутый текст" << RESET << '\n' <<
        "5. " << BLINK << "BLINK - мигающий текст" << RESET << '\n' <<
        "6. " << REVERSE << "REVERSE - инверсия цветов" << RESET << '\n' <<
        "7. " << HIDDEN << "HIDDEN - скрытый текст" << RESET << '\n';
}

inline void color_table()
{
    cout <<
        "1. " << WHITE << "BLACK" << RESET << '\n' <<
        "2. " << RED << "RED" << RESET << '\n' <<
        "3. " << GREEN << "GREEN" << RESET << '\n' <<
        "4. " << YELLOW << "YELLOW" << RESET << '\n' <<
        "5. " << BLUE << "BLUE" << RESET << '\n' <<
        "6. " << MAGENTA << "MAGENTA" << RESET << '\n' <<
        "7. " << CYAN << "CYAN" << RESET << '\n' <<
        "8. " << WHITE << "WHITE" << RESET << '\n';
}


inline void text_style()
{
    cout
        << "1. " << BOLD << "BOLD" << RESET << '\n'
        << "2. " << DIM << "DIM" << RESET << '\n'
        << "3. " << ITALIC << "ITALIC" << RESET << '\n'
        << "4. " << UNDERLINE << "UNDERLINE" << RESET << '\n'
        << "5. " << BLINK << "BLINK" << RESET << '\n'
        << "6. " << REVERSE << "REVERSE" << RESET << '\n'
        << "7. " << HIDDEN << "HIDDEN" << RESET << '\n';
}

#endif //UNTITLED3_COLORS_H
