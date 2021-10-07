#include <iostream>
using namespace std;

int n;
int grid[500][500];
int answer;
// 오른쪽->왼쪽, 왼쪽->오른쪽, 위->아래, 아래->위
// 0 2 1 3 순서
// 오->왼, 위->아래, 왼->오, 아->위
int order[4] = {0, 1, 2, 3};
// 7 7 10 10 1 1 2 2 5 a 
int dir[4][10][3] = {
  {
    {-1, 0, 7}, {1, 0, 7}, {-1, -1, 10}, {1, -1, 10}, {-1, 1, 1}, {1, 1, 1}, {-2, 0, 2}, {2, 0, 2}, {0, -2, 5}, {0, -1, 0}
  },
  {
    {0, -1, 7}, {0, 1, 7}, {1, -1, 10}, {1, 1, 10}, {-1, -1, 1}, {-1, 1, 1}, {0, -2, 2}, {0, 2, 2}, {2, 0, 5}, {1, 0, 0}
  },
  {
    {-1, 0, 7}, {1, 0, 7}, {-1, 1, 10}, {1, 1, 10}, {1, -1, 1}, {-1, -1, 1}, {-2, 0, 2}, {2, 0, 2}, {0, 2, 5}, {0, 1, 0}
  },
  {
    {0, -1, 7}, {0, 1, 7}, {-1, -1, 10}, {-1, 1, 10}, {1, -1, 1}, {1, 1, 1}, {0, -2, 2}, {0, 2, 2}, {-2, 0, 5}, {-1, 0, 0}
  }
};

void print_grid () {
  for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++) {
      cout << grid[i][j] << ' ';
    }
    cout << endl;
  }
  cout << endl;
}

bool scope_check(int x, int y) {
  return x>=0 && x<n && y>=0 && y<n;
}

void update_sand(int x, int y, int dir_index) {
  int origin_sand = grid[x][y];
  int accum_sum = 0;
  grid[x][y] = 0;
  for(int i=0;i<9;i++) {
    int *temp_coord = dir[dir_index][i];
    int next_x = x + temp_coord[0];
    int next_y = y + temp_coord[1];
    int percentage = temp_coord[2];

    int temp_sand = int(float(origin_sand) * percentage / 100.0);
    accum_sum += temp_sand;

    if(scope_check(next_x, next_y)) {
      grid[next_x][next_y] += temp_sand;
    }
    else {
      answer += temp_sand;
    }
  }
  int alpha_x = x + dir[dir_index][9][0];
  int alpha_y = y + dir[dir_index][9][1];

  if(scope_check(alpha_x, alpha_y)) {
    grid[alpha_x][alpha_y] += (origin_sand - accum_sum);
  }
  else {
    answer += (origin_sand - accum_sum);
  }
}

int main() {
  scanf("%d", &n);
  int total_sand = 0;
  for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++) {
      scanf("%d", &grid[i][j]);
      total_sand += grid[i][j];
    }
  }
  int x = n/2;
  int y = n/2;
  int cnt = 0;
  int number = 1;
  bool flag = false;

  while(true) {
    if(cnt != 0 && cnt % 2 == 0) number++;
    int dir_index = cnt % 4;

    if(dir_index == 0) {
      for(int i=0;i<number;i++) {
        y -= 1;
        update_sand(x, y, dir_index);
        if(x == 0 && y == 0) {
          flag = true;
          break;
        }
      }
    }
    else if(dir_index == 1) {
      for(int i=0;i<number;i++) {
        x += 1;
        update_sand(x, y, dir_index);
        if(x == 0 && y == 0) {
          flag = true;
          break;
        }
      }
    }
    else if(dir_index == 2) {
      for(int i=0;i<number;i++) {
        y += 1;
        update_sand(x, y, dir_index);
        if(x == 0 && y == 0) {
          flag = true;
          break;
        }
      }
    }
    else {
      for(int i=0;i<number;i++) {
        x -= 1;
        update_sand(x, y, dir_index);
        if(x == 0 && y == 0) {
          flag = true;
          break;
        }
      }
    }
    cnt++;
    if(flag) break;
  }

  cout << answer << endl;
}