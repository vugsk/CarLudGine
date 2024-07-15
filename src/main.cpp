
#include <iostream>
#include <ncurses.h>

using size_X = int;
using size_Y = int;

class IWindow
{
public:
	virtual void print(const char* format, ...) const = 0;
	virtual void mvprint(size_X x, size_Y y,
						 const char* format, ...) const = 0;
	[[nodiscard]] virtual IWindow* createWindow(size_X x, size_Y y,
												size_X width,
												size_Y height) const = 0;

	[[nodiscard]] virtual size_X getX() const = 0;
	[[nodiscard]] virtual size_Y getY() const = 0;

	virtual ~IWindow() = default;
};

class Window : public IWindow
{
public:
	Window(size_X width, size_Y height, WINDOW* window)
		: _width(width), _height(height), _window(window)
	{
		box(_window, 0, 0);
		wrefresh(_window);
	}

	~Window() override
	{
		delwin(_window);
	}

	[[nodiscard]] IWindow *createWindow(size_X x, size_Y y,
												size_X width,
												size_Y height) const final
	{
		return nullptr;
	}

	void print(const char *format, ...) const final
	{
		va_list args;
		va_start(args, format);
		vw_printw(_window, format, args);
		wrefresh(_window);
		va_end(args);
	}

	void mvprint(size_X x, size_Y y,
	             const char* format, ...) const final
	{
		va_list args;
		va_start(args, format);
		wmove(_window, y, x);
		vw_printw(_window, format, args);
		wrefresh(_window);
		va_end(args);
	}

	[[nodiscard]] size_X getX() const final
	{
		return _width;
	}

	[[nodiscard]] size_Y getY() const final
	{
		return _height;
	}

private:
	size_X _width;
	size_Y _height;
	WINDOW* _window;
};




class Screen : public IWindow
{
public:
	static Screen *GetInstance(size_X width = 0, size_Y height = 0)
	{
		return ptrWindow ?: new Screen(width, height);
	}

	void print(const char *format, ...) const final
	{
		va_list args;
		va_start(args, format);
		vw_printw(_window, format, args);
		wrefresh(_window);
		va_end(args);
	}

	void mvprint(size_X x, size_Y y,
				 const char* format, ...) const final
	{
		va_list args;
		va_start(args, format);
		wmove(_window, y, x);
		vw_printw(_window, format, args);
		wrefresh(_window);
		va_end(args);
	}

	[[nodiscard]] IWindow *createWindow(size_X x, size_Y y,
                                        size_X width,
                                        size_Y height) const final
	{
		return new Window(width, height, newwin(y, x, height, width));
	}

	[[nodiscard]] size_X getX() const final
	{
		return _width;
	}

	[[nodiscard]] size_Y getY() const final
	{
		return _height;
	}

private:
	explicit Screen(size_X width = 0, size_Y height = 0)
	{
		initscr();
		_window = stdscr;
		_width = width ?: getmaxx(_window);
		_height = height ?: getmaxy(_window);
	}

	~Screen() override
	{
		endwin();
	}

	static Screen *ptrWindow;

	size_X _width;
	size_Y _height;
	WINDOW* _window;
};

Screen *Screen::ptrWindow = nullptr;



int main()
{
	IWindow* wt = Screen::GetInstance();
	wt->print("%d %d", wt->getX(), wt->getY());

	IWindow* win = wt->createWindow(10, 5, 20, 5);
	win->print("%d %d", win->getX(), win->getY());

	getch();

	delete win;
	delete wt;

    return 0;
}