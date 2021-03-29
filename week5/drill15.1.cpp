#include "Simple_window.h"
#include "Graph.h"

double one(double x){return 1;}

double slope(double x){return x/2;}

double square(double x){return x*x;}

double sloping_cos(double x){return cos(x)+slope(x);}

int main()
{
    using namespace Graph_lib;
	
	const int xmax=600;
	const int ymax=600;

	Simple_window win{Point{100,100}, xmax, ymax, "Function graphs"};
	
	const int x_orig=xmax/2;
	const int y_orig=ymax/2;
	Point orig{x_orig,y_orig};
	
	const int xlength=xmax-200;
	const int ylength=ymax-200;

	const int xscale=20;
	const int yscale=20;

	const int rmin=-10;
	const int rmax=11;
	
	const int n_points=400;
	
	Axis x {Axis::x, Point{100,y_orig}, xlength, xlength/xscale, "1==20 pixels"};
	Axis y {Axis::y, Point{x_orig, ylength+100}, ylength, ylength/yscale, "1==20 pixels"};

	x.set_color(Color::red);
	y.set_color(Color::red);

	Function s1{one, rmin, rmax, orig, n_points, xscale, yscale};
	
	Function s2{slope, rmin, rmax, orig, n_points, xscale, yscale};
	Text t{Point{100,ymax-220}, "x/2"};

	Function s3{square, rmin, rmax, orig, n_points, xscale, yscale};

	Function s4{cos, rmin, rmax, orig, n_points, xscale, yscale};
	s4.set_color(Color::blue);

	Function s5{sloping_cos, rmin, rmax, orig,n_points, xscale, yscale};

	win.attach(x);
	win.attach(y);
	win.attach(s1);
	win.attach(s2);
	win.attach(s3);
	win.attach(s4);
	win.attach(s5);
	win.attach(t);

	win.wait_for_button();

}