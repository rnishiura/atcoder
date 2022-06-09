#include <bits/stdc++.h>
using namespace std;

#define TRIAL_MAX 18000
// #define COMMAND_MAX 10000

// int N, T;

void show_map(char** map, int N) {
  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++) {
      cout << map[i][j];
    }
    cout << endl;
  }
}

// DONE セグメンテーションエラー：壁への対応
// DONE ランダム生成におけるリアルタイムパフォーマンス評価
// DONE y0, x0が動いていない！！

bool map_move(char cmd, char** map, int N, int z[2]) {
  char tmp;
  int y0 = z[0];
  int x0 = z[1];

  switch(cmd) {
    case 'U':
      if (y0 == 0) return false;
      map[y0][x0] = map[y0-1][x0];
      map[y0-1][x0] = '0';
      z[0]--;
      break;
    case 'R':
      if (x0 == N-1) return false;
      map[y0][x0] = map[y0][x0+1];
      map[y0][x0+1] = '0';
      z[1]++;
      break;
    case 'D':
      if (y0 == N-1) return false;
      map[y0][x0] = map[y0+1][x0];
      map[y0+1][x0] = '0';
      z[0]++;
      break;
    case 'L':
      if (x0 == 0) return false;
      map[y0][x0] = map[y0][x0-1];
      map[y0][x0-1] = '0';
      z[1]--;
      break;
  }

  return true;
}

void map_cpy(char** _map, char** map, int N) {
  for(int i=0; i<N; i++) for(int j=0; j<N; j++) map[i][j] = _map[i][j];
}

int c2i(char c) {
  if('a' <= c && c <= 'f') {
    return 10 + int(c - 'a');
  }
  return int(c - '0');
}

// DONE a U 6 => 1に誤ってなっている
bool matches(char c, char dir, char neighbor) {
  c = c2i(c);
  neighbor = c2i(neighbor);

  int i_dir;
  switch(dir) {
    case 'L':
      i_dir = 0; break;
    case 'U':
      i_dir = 1; break;
    case 'R':
      i_dir = 2; break;
    case 'D':
      i_dir = 3; break;
  }

  if (((c >> i_dir) % 2) && ((neighbor >> ((i_dir+2) % 4)) % 2)) return true;
  return false;
}

bool matches(char** map, int N, int y0, int x0, char dir) {
  char c = map[y0][x0];
  switch(dir) {
    case 'L':
      if(x0 == 0) return false;
      return matches(c, dir, map[y0][x0-1]);
    case 'U':
      if(y0 == 0) return false;
      return matches(c, dir, map[y0-1][x0]);
    case 'R':
      if(x0 == N-1) return false;
      return matches(c, dir, map[y0][x0+1]);
    case 'D':
      if(y0 == N-1) return false;
      return matches(c, dir, map[y0+1][x0]);
  }
  return false;
}

void dir2diff(char dir, int pq[2]) {
  switch(dir) {
    case 'L': pq[0] =  0; pq[1] = -1; break;
    case 'U': pq[0] = -1; pq[1] =  0; break;
    case 'R': pq[0] =  0; pq[1] = +1; break;
    case 'D': pq[0] = +1; pq[1] =  0; break;
  }
}

int calc_score(char** map, char** id_map, int N) {
  bool joint[N][N][4];
  for(int i=0; i<N-1; i++) for(int j=0; j<N-1; j++) {
    joint[i][j][0] = matches(map, N, i, j, 'L');
    joint[i][j][1] = matches(map, N, i, j, 'U');
    joint[i][j][2] = matches(map, N, i, j, 'R');
    joint[i][j][3] = matches(map, N, i, j, 'D');
  } 

  int id[N][N];
  for(int i=0; i<N; i++) for(int j=0; j<N; j++) id[i][j] = -1;

  int dij[2];
  char dirs[] = {'L', 'U', 'R', 'D'};
  // char dirs[] = {'L', 'U'};
  int cnt = 0;
  for(int i=0; i<N; i++) for(int j=0; j<N; j++) {
    if ( id[i][j] == -1 ) id[i][j] = cnt++;

    for(int d=0; d<4; d++) {
      char c = dirs[d];
      dir2diff(c, dij);
      int yn = i+dij[0];
      int xn = j+dij[1];

      if (matches(map, N, i, j, c)) {
        if(id[yn][xn] == -1) id[yn][xn] = id[i][j];
        else if(id[yn][xn] != id[i][j]) {
          int old_id = id[yn][xn];
          for(int k=0; k<N; k++) for(int l=0; l<N-1; l++) if (id[k][l] == old_id) id[k][l] = id[i][j]; 
        }
        // else {
        //   id[i][j] = id[yn][xn];
        // }
      }
      else {
        if ( id[yn][xn] == -1 ) id[yn][xn] = cnt++;
      }
    }

    // cout << endl;
    // for(int i=0; i<N; i++) {
    //   for(int j=0; j<N; j++) {
    //     cout << (char)('a' + id[i][j]);
    //   } 
    //   cout << endl;
    // }
  }

  int max_score = 0;
  for(int k=0; k<cnt; k++) {
    int score = 0;
    for(int i=0; i<N; i++) for(int j=0; j<N; j++) {
      if (id[i][j] == k) score++;
    }
    if (score > max_score) max_score = score;
  }

  for(int i=0; i<N; i++) 
    for(int j=0; j<N; j++) 
      id_map[i][j] = (char)('a' + id[i][j]);
      

  return max_score;
}

int calc_score(char** map, int N) {
  char** tmp = (char**) malloc(sizeof(char*) * N);
  for(int i=0; i<N; i++) tmp[i] = (char*) malloc(sizeof(char) * N);

  return calc_score(map, tmp, N);
}

void sub2(void) {
  char c, dir, n;
  cin >> c >> dir >> n;
  cout << matches(c, dir, n) << endl;
}

int sub(void) {
  int N, T;
  cin >> N >> T;

  char** map = (char**) malloc(sizeof(char*) * N);
  for(int i=0; i<N; i++) map[i] = (char*) malloc(sizeof(char) * N);

  char c;
  int z[2];
  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++) {
      cin >> c;
      map[i][j] = c;
      if (c == '0') {
        z[0] = i;
        z[1] = j;
      }
    }
  }

  cout << calc_score(map, N) << endl;
  return 0;
}

int main(void) {
  int N, T;
  cin >> N >> T;

  char** map = (char**) malloc(sizeof(char*) * N);
  for(int i=0; i<N; i++) map[i] = (char*) malloc(sizeof(char) * N);

  char** current_map = (char**) malloc(sizeof(char*) * N);
  for(int i=0; i<N; i++) current_map[i] = (char*) malloc(sizeof(char) * N);

  char** best_map = (char**) malloc(sizeof(char*) * N);
  for(int i=0; i<N; i++) best_map[i] = (char*) malloc(sizeof(char) * N);


  char c;
  int z[2];
  int x0, y0;
  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++) {
      cin >> c;
      map[i][j] = c;
      if (c == '0') {
        y0 = i;
        x0 = j;
      }
    }
  }
  z[0] = y0;
  z[1] = x0;

  string best_command = "";
  int best_score = 0;
  // int best_com_len = 0;
  char direction[] = {'U', 'R', 'D', 'L'};
  srand(63);
  // srand(int(time(NULL)));
  int cnt_t = 0, cnt_c = 0;
  while(cnt_t < TRIAL_MAX) {
    map_cpy(map, current_map, N);

    z[0] = y0;
    z[1] = x0;

    int com_len = 2*N^3+1;

    string cmd;
    if (best_command.length() == 0) {
      cnt_c = 0;
      cmd = "";
    } else {
      cnt_c = rand() % best_command.length();
      cmd = best_command.substr(0, cnt_c);
      for(int i=0; i<cnt_c; i++)  map_move(cmd[i], current_map, N, z);
    }

    // cnt_c = 0;
    // cmd = "";

    while(cnt_c < com_len) {
      char next_move = direction[rand() % 4];

      int pq[2], rs[2];
      dir2diff(cmd[cnt_c-1], pq);
      dir2diff(next_move, rs);
      if(pq[0]+rs[0] == 0 && pq[1]+rs[1] == 0) continue;

      bool ret = map_move(next_move, current_map, N, z);
      if (!ret) continue;
      
      cmd += next_move;
      // cout << cmd << endl;
      
      cnt_c++;

      int score = calc_score(current_map, N);

      // TODO 閉ぢた回路の検出
      // TODO 来た場所に戻らない
      // DONE TRIALのBEST遺伝
      // TODO その改良の余地？
      // DONE 制限時間ギリギリまで試行
      if (score > best_score) {
        best_score = score;
        best_command = cmd;
        map_cpy(current_map, best_map, N);
      }
    }

    cnt_t++;
  }

  cout << best_command << endl;
  // cout << best_score << endl;

  // show_map(best_map, N);

  // // bool beep = false;
  // // for (int i=0; i<best_command.length(); i++) {
  // //   if(!map_move(best_command[i], map, N, z))
  // // }

  // cout << endl;

  // calc_score(best_map, current_map, N);
  // show_map(current_map, N);

  return 0;
}

