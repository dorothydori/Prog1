#include "Simple_window.h"
#include "Graph.h"

int main()
try{
    using namespace Graph_lib;

    Simple_window win{Point{100, 100}, 800, 1000, "Window"};
    int m=800;
    int sz=800;
    int m_grid=100;
    int sz_grid=100;

    Lines grid;

    for(int i=m_grid; i < sz; i+=m_grid){
        grid.add(Point{i,0},Point{i,sz});

    }
    for(int i=sz_grid; i < m; i+=sz_grid){
        grid.add(Point{0,i},Point{m,i});

    }

    Rectangle a1{Point {100,100},100,100};
    a1.set_fill_color(Color::red);
    Rectangle a2{Point {200,200},100,100};
    a2.set_fill_color(Color::red);
    Rectangle a3{Point {300,300},100,100};
    a3.set_fill_color(Color::red);
    Rectangle a4{Point {400,400},100,100};
    a4.set_fill_color(Color::red);
    Rectangle a5{Point {500,500},100,100};
    a5.set_fill_color(Color::red);
    Rectangle a6{Point {600,600},100,100};
    a6.set_fill_color(Color::red);
    Rectangle a7{Point {700,700},100,100};
    a7.set_fill_color(Color::red);
    Rectangle a8{Point {0,0},100,100};
    a8.set_fill_color(Color::red);

    Image i{Point {0,300},"butterfly.jpg"};
    Image k{Point {100,600},"butterfly.jpg"};
    Image j{Point {600,100},"butterfly.jpg"};

    win.attach(i);
    win.attach(k);
    win.attach(j);

    win.attach(a1);
    win.attach(a2);
    win.attach(a3);
    win.attach(a4);
    win.attach(a5);
    win.attach(a6);
    win.attach(a7);
    win.attach(a8);

    win.attach(grid);

    Image u{Point{0,0}, "bridge.jpg"};
    win.attach(u);
    win.wait_for_button();

    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
        {
            win.wait_for_button();
            if(j < 7)
            
                u.move(100,0);
              
            else
                u.move(-700,100);
    }

    win.wait_for_button();

}
catch(exception& e){
    cerr <<"exception: " << e.what() << '\n';
    return 1;
}
catch(...){
    cerr <<"error\n";
    return 2;
}