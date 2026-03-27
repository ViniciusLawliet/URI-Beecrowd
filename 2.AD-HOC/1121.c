/**
 * @author vinicius lawliet
 * @brief 
 * @version 0.1
 * 
 * problem: 1021 - Robo Colecionador
 * 
 */


#include <stdio.h>

typedef struct {
    int x, y, itens, dir;
} Robo;

char arena[100][100];
char coman[50001];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int get_dir(char x) {
    if (x == 'N') return 0;
    if (x == 'L') return 1;
    if (x == 'S') return 2;
    if (x == 'O') return 3;
    return -1;
}

void move(Robo *r, int limit_x, int limit_y) {
    int nx = r->x + dx[r->dir];
    int ny = r->y + dy[r->dir];

    if (nx < 0 || nx >= limit_x || ny < 0 || ny >= limit_y) return;
    if (arena[nx][ny] == '#') return;

    if (arena[nx][ny] == '*') {
        arena[nx][ny] = '.';
        r->itens++;
    }

    r->x = nx;
    r->y = ny;
}

void rotate(Robo *r, char comando) {
    if (comando == 'D')
        r->dir = (r->dir + 1) % 4;
    else if (comando == 'E')
        r->dir = (r->dir + 3) % 4;
}

int main() {

    Robo bot;
    
    int N, M, S;
    while (scanf("%d %d %d", &N, &M, &S) == 3 && (N || M || S)) {

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                scanf(" %c", &arena[i][j]);

                if (arena[i][j] == 'N' || arena[i][j] == 'S' || arena[i][j] == 'L' || arena[i][j] == 'O') {
                    bot.x = i;
                    bot.y = j;
                    bot.dir = get_dir(arena[i][j]);
                    arena[i][j] = '.';
                }
            }
        }

        bot.itens = 0;
        scanf("%50000s", coman);

        for (int i = 0; i < S; i++) {
            if (coman[i] == 'F')
                move(&bot, N, M);
            else
                rotate(&bot, coman[i]);
        }

        printf("%d\n", bot.itens);
    }

    return 0;
}