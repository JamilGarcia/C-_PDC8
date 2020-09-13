#include <curses.h>
WINDOW *ventana;

int main()
{
    int MaxX, MaxY;
    int tecla = 1;
    initscr();
    getmaxyx(stdscr, MaxY, MaxX);
    if (!has_colors())
    {
        endwin();
        return 1;
    }
    cbreak();
    noecho();
    nonl();
    intrflush(ventana, FALSE);
    keypad(ventana, TRUE);
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLUE);
    ventana = newwin(MaxY, MaxX, 0, 0);
    WINDOW *caja1 = newwin((MaxY - (MaxY * 0.50)), (MaxX - (MaxX * 0.50)), 0, 0),
           *caja2 = newwin((MaxY - (MaxY * 0.50)), (MaxX - (MaxX * 0.50)), 0, MaxX / 2),
           *caja3 = newwin((MaxY - (MaxY * 0.50)), (MaxX - (MaxX * 0.50)), MaxY / 2, 0),
           *caja4 = newwin((MaxY - (MaxY * 0.50)), (MaxX - (MaxX * 0.50)), MaxY / 2, MaxX / 2);

    wbkgd(ventana, COLOR_PAIR(1));
    wbkgd(caja1, COLOR_PAIR(1));
    wbkgd(caja2, COLOR_PAIR(1));
    wbkgd(caja3, COLOR_PAIR(1));
    wbkgd(caja4, COLOR_PAIR(1));

    while (tecla != 27)
    {
        tecla = getch();
        if(tecla == 27){
            endwin();
            return 0; 
        }
        box (caja1, ACS_VLINE, ACS_HLINE);
        touchwin(caja1); 
        wrefresh(caja1); 

        tecla = getch();
        if(tecla == 27){
            endwin();
            return 0; 
        }
        wclear(caja1); 
        box (caja2, ACS_VLINE, ACS_HLINE);
        touchwin(caja2); 
        wrefresh(caja2); 

        tecla = getch();
        if(tecla == 27){
            endwin();
            return 0; 
        }
        wclear(caja2); 
        box (caja3, ACS_VLINE, ACS_HLINE);
        touchwin(caja3); 
        wrefresh(caja3); 

        tecla = getch();
        if(tecla == 27){
            endwin();
            return 0; 
        }
        wclear(caja3); 
        box (caja4, ACS_VLINE, ACS_HLINE);
        touchwin(caja4); 
        wrefresh(caja4);


        tecla = getch(); 
        wclear(caja4);  
        
    }
    getch();
    endwin();
    return 0; 
}
