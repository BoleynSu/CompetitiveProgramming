#include <stdio.h>
#include <stdlib.h>

struct Area {
    int terrain; //0为土地，1为山地
    int bonus; //土地bonus值
    int belong; //0为无归属，1为玩家一，2为玩家2
    int soldier_num; //该土地上目前的士兵数目
};

int height, width; //地图高和宽
int my_player_id; //我的玩家编号
int attack_factor; //攻击损失系数
int round; //当前回合数
Area area[6][8]; //地图

int soldier_num; //每回合新出现的士兵

//初始化地图信息和局面信息
void init() {
    
    //读取地形数据
    scanf("%d%d", &height, &width);
    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
            scanf("%d", &area[i][j].terrain);
        }
    }
    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
            scanf("%d", &area[i][j].bonus);
        }
    }
    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
            scanf("%d", &area[i][j].belong);
        }
    }

    //初始化复制
    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
            area[i][j].soldier_num = 0;
        }
    }
    round = 0;

    scanf("%d%d", &my_player_id, &attack_factor);
}

//计算bonus总和
int get_bonus(int player_id) {
    int bonus = 0;
    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
            if (area[i][j].belong == player_id) {
                bonus += area[i][j].bonus;
            }
        }
    }
    return bonus;
}

//检查一区域是否可用
bool check_area(int x, int y) {
    return (x<height && y<width && x>=0 && y>=0 && area[x][y].terrain==0);
}

//检查两区域是否相邻（参数为两区域坐标）
bool check_near(int x1, int y1, int x2, int y2) {
    int dx[]={0, 1, 0, -1};
    int dy[]={1, 0, -1, 0};
    for (int d=0; d<4; d++) {
        if (x1 + dx[d] == x2 && y1 + dy[d] == y2) return true;
    }
    return false;
}

//检查游戏是否结束
bool check_end() {
    if (round > 300) return true;

    //检查是否所有可用土地属于同一个玩家
    int player_id = -1;
    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
            if (area[i][j].terrain == 0) {
                if (player_id == -1) player_id = area[i][j].belong;
                else if (area[i][j].belong != player_id) return false;
            }
        }
    }

    return true;
}

//放置士兵
void set_soldier(int player_id, int x, int y, int number) {
    if (!check_area(x, y)) return ;
    if (area[x][y].belong != player_id) return ;
    area[x][y].soldier_num += number;

    if (player_id == my_player_id) {
        soldier_num -= number;
        printf("1 %d %d %d\n", x, y, number);
    }
}

//进行攻击
void attack(int player_id, int x1, int y1, int x2, int y2, int number) {
    if (!check_area(x1, y1) || !check_area(x2, y2)) return ;
    if (area[x1][y1].belong != player_id || area[x2][y2].belong == player_id) return ;
    if (!check_near(x1, y1, x2, y2)) return ;
    if (area[x1][y1].soldier_num < number) return ;
    
    int A = number;
    int B = area[x2][y2].soldier_num;
    int K = attack_factor;
    int C = (int)(K*B/10+1);
    if (A > C) {
        area[x2][y2].belong = player_id;
        area[x2][y2].soldier_num = A - C;
        area[x1][y1].soldier_num -= A;
    } else {
        int D = (int)((A-1)*10/K);
        area[x2][y2].soldier_num -= D;
        area[x1][y1].soldier_num -= A;
    }

    if (player_id == my_player_id) {
        printf("2 %d %d %d %d %d\n", x1, y1, x2, y2, number);
    }
}

//决策如何放置士兵
//请修改此函数以进行放置士兵的决策
void set_all_soldier() {
    soldier_num = get_bonus(my_player_id);
    while (soldier_num > 0) {
        int dx[]={0, 1, 0, -1};
        int dy[]={1, 0, -1, 0}; 
        for (int i1=0; i1<height; i1++) {
            for (int j1=0; j1<width; j1++) {
                if (area[i1][j1].belong==my_player_id) {
                    for (int d=0; d<4; d++) {
                        int i2=i1+dx[d], j2=j1+dy[d];
                        if (check_area(i2, j2) && area[i2][j2].belong != my_player_id) {
                            if (soldier_num > 0) {
                                set_soldier(my_player_id, i1, j1, (rand() % soldier_num) + 1);
                            }
                        }
                    }
                }
            }
        }
    }
}

//决策如何进攻
//请修改此函数以进行进攻的决策
void do_all_attack() {
    bool is_attack;
    do {
        is_attack = false;
        int dx[]={0, 1, 0, -1};
        int dy[]={1, 0, -1, 0};
        for (int i1=0; i1<height; i1++) {
            for (int j1=0; j1<width; j1++) {
                if (area[i1][j1].belong==my_player_id && area[i1][j1].soldier_num > 0) {
                    for (int d=0; d<4; d++) {
                        int i2=i1+dx[d], j2=j1+dy[d];
                        if (check_area(i2, j2) && area[i2][j2].belong != my_player_id) {
                            attack(my_player_id, i1, j1, i2, j2, area[i1][j1].soldier_num);
                            is_attack = true;
                            break;
                        }
                    }
                }
            }
            if (is_attack) break;
        }
    } while(is_attack);
}

//读取对手的操作
void read_operator(int player_id) {
    while(true) {
        int type,x,y,x1,y1,x2,y2,number;
        scanf("%d", &type);
        if (type == -1) break;
        if (type == 1) {
            scanf("%d%d%d", &x, &y, &number);
            set_soldier(player_id, x, y, number);
        } else if (type == 2) {
            scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &number);
            attack(player_id, x1, y1, x2, y2, number);
        }
    }
}

int main() {
    init();
    int cur_player_id = 1;
    while (!check_end()) {
        round++;
        if (cur_player_id == my_player_id) {
            //自己行动
            set_all_soldier();
            do_all_attack();
            printf("-1\n");
            fflush(stdout);
        } else {
            //对手行动
            read_operator(cur_player_id);
        }
        if (cur_player_id == 1) cur_player_id = 2;
        else cur_player_id = 1;
    }
	return 0;
}
