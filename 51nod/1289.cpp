//
// 1289 大鱼吃小鱼
//

#include <bits/stdc++.h>

using namespace std;

int arr[100005];

int main() {
    int index = 0, left = 0;
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        int size, dir;
        scanf("%d %d", &size, &dir);
        if(dir == 0) {
            if(index == 0) {
                left++;
            }
            else {
                while(index) {
                    int size0 = arr[index - 1];
                    if(size > size0)
                        index--;
                    else
                        break;
                }

                if(index == 0)
                    left++;
            }
        }
        else
            arr[index++] = size;
    }

    printf("%d\n", index + left);
    return 0;
}
