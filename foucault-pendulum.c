#include <ncurses.h>
#include <math.h>
#include <unistd.h>

#define PI 3.14159265358979
#define G 9.81
#define L 10
#define DT 0.05
#define OMEGA 0.00007292
#define LATITUDE 60.0 

#define WIDTH 24
#define HEIGHT 80

double acc(double theta) {
    return -(G / L) * sin(theta);
}

void rk(double *theta, double *omega) {
    double k1_theta = *omega * DT;
    double k1_omega = acc(*theta) * DT;

    double k2_theta = (*omega + k1_omega / 2) * DT;
    double k2_omega = acc(*theta + k1_theta / 2) * DT;
    
    double k3_theta = (*omega + k2_omega / 2) * DT;
    double k3_omega = acc(*theta + k2_theta / 2) * DT;

    double k4_theta = (*omega + k3_omega) * DT;
    double k4_omega = acc(*theta + k3_theta) * DT;

    *theta += (k1_theta + 2 * k2_theta + 2 * k3_theta + k4_theta) / 6;
    *omega += (k1_omega + 2 * k2_omega + 2 * k3_omega + k4_omega) / 6;
}   

int main() {

    initscr();
    noecho();
    curs_set(0);
    nodelay(stdscr, TRUE);
    start_color();

    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_BLUE, COLOR_BLACK);
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);

    double theta = 0.3;
    double omega = 0.0;
    double phi = 0.0;
    double omega_foucault = OMEGA * sin(LATITUDE * PI / 180.0);

    int center_x = HEIGHT / 2;
    int center_y = WIDTH / 2;
    int ground_y = WIDTH - 2;

    while (1) {
        clear();
        
        rk(&theta, &omega);
        phi += omega_foucault * DT;

        int x = center_x + (int)(L * sin(theta) * cos(phi));
        int y = center_y + (int)(L * cos(theta));
        int shadow_x = center_x + (int)(L * sin(theta) * cos(phi) * 0.7);

        attron(COLOR_PAIR(1));
        mvaddch(center_y - 1, center_x, 'O');
        attroff(COLOR_PAIR(1));

        attron(COLOR_PAIR(3));
        for (int i = 1 ; i < y - center_y ; i++) {
            int xi = center_x + (x - center_x) * i / (y - center_y);
            mvaddch(center_y + i, xi, '|');
        }
        attroff(COLOR_PAIR(3));

        attron(COLOR_PAIR(2));
        mvaddch(y, x, 'O');
        attroff(COLOR_PAIR(2));

        attron(COLOR_PAIR(4));
        mvaddch(ground_y, shadow_x, 'O');
        attroff(COLOR_PAIR(4));

        refresh();
        usleep(50000);

        if (getch() != ERR) break;
    }

    endwin();
    return 0;
}

