#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;

int main()
{

	Point tl{100,100};
	Simple_window win{tl,600,400,"My window"};

	Axis xa{Axis::x, Point{20,300}, 280, 10, "x axis"};
	
	Axis ya{Axis::y, Point{20,300}, 280, 10, "y axis"};
	//ya.set_color(Color::cyan);
	//ya.label.set_color(Color::dark_red);
	
	Function sine (sin,0,100,Point{20,150},1000,50,50);
	sine.set_color(Color::blue);

	Polygon poly;
	poly.add(Point{300,200});
	poly.add(Point{350,100});
	poly.add(Point{400,200});
	poly.set_color(Color::red);
	poly.set_style(Line_style::dash);
	poly.set_style(Line_style(Line_style::dash,4));
	
	Rectangle r(Point{200,200},100,50);
	r.set_fill_color(Color::yellow);

    Closed_polyline poly_rect;
    poly_rect.add(Point{100,50});
    poly_rect.add(Point{200,50});
    poly_rect.add(Point{200,100});
    poly_rect.add(Point{100,100});
    poly_rect.add(Point{50,75});
    poly_rect.set_style(Line_style(Line_style::dash,2));
    poly_rect.set_fill_color(Color::green);

    Text t(Point{150,150},"Hello, graphical world!");
    //t.set_font(Font::times_bold);
    t.set_font(20);

    Image ii(Point{350,250},"grumpycat.jpg");

	win.attach(xa);
	win.attach(ya);
	win.attach(sine);
	win.attach(poly);
	win.attach(r);
	win.attach(poly_rect);
	win.attach(t);
	win.attach(ii);

	win.wait_for_button();
}