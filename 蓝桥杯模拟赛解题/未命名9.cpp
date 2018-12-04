#include<iostream>  
using namespace std;  
class data{  
public:  
    int x,y;  
    int* b;  
    data(){  
        x = 0;  
        y = 0;  
        b = NULL;  
    }  
};  
int static A[9][9] = {  
    0,2,6,0,0,0,0,0,0,
0,0,0,5,0,2,0,0,4,
0,0,0,1,0,0,0,0,7,
0,3,0,0,2,0,1,8,0,
0,0,0,3,0,9,0,0,0,
0,5,4,0,1,0,0,7,0,
5,0,0,0,0,1,0,0,0,
6,0,0,9,0,7,0,0,0,
0,0,0,0,0,0,7,5,0 
  
};  
data findm();//找到最后的空格的地址  
int check(int i, int j,int num);//检查当前是否符合的规则  
int out_answer();  
  
int f( int n ){  
    if(n == 0){  
        cout<<"已经填完了，不需要进行填写"<<endl;  
        exit(0);  
    }  
    data d = findm();  
    for(int i = 1; i <= 9; i++){  
         *(d.b) = i;  
         int x = d.x;  
         int y = d.y;  
         if( check(x,y,i) ){//如果检查通过  
             if(n>1){  
                 if(f(n-1))//填写成功  
                     return 1;  
             }  
             else{  
                 out_answer();//输出结果  
                 return 1;  
             }   
         }  
    }  
    if(i == 10){//说明1到9都不能符合规则。需要返回上一个空格重新填写  
         *(d.b) = 0;//清空该空格  
         return 0;  
    }  
    return 0;  
  
}  
int check(int i, int j,int num){//i行，j 列 。数值 num  
    int x = 0;  
    int y = 0;  
    for(y = 0; y < 9; y++){  
        if(A[i][y] == num && y != j){  
            return 0;  
        }  
    }  
    for(x = 0; x < 9; x++){  
        if(A[x][j] == num && x != i){  
            return 0;  
        }  
    }  
    int a = 0;  
    int b = 0;  
    a = i/3*3;  
    b = j/3*3;  
    for(x = a; x < a+3; x++){  
        for(y = b; y < b+3; y++){  
            if(A[x][y] == num && x!=i && y!=j ){  
                return 0;  
            }  
        }  
    }  
    return 1;  
}  
int count(){  
    int num = 0;  
    for(int x = 0; x < 9; x++){  
        for(int y = 0; y < 9; y++){  
            if(A[x][y] == 0 ){  
                num++;  
            }  
        }  
    }  
    return num;  
}  
data findm(){  
    data d;  
    for(int x = 8;x >= 0; x--){  
        for(int y = 8; y >= 0; y--){  
            if(A[x][y] == 0){  
                d.b = &A[x][y];  
                d.x = x;  
                d.y = y;  
                return d;  
            }  
        }  
    }  
    cout<<"\n findm:end \n";  
    return d;  
}  
int out_answer(){  
    for(int x = 0; x < 9; x++){  
        for(int y = 0; y < 9; y++){  
            if(y==0){  
                cout<<endl;  
            }  
            cout<<A[x][y]<<" ";  
        }  
    }  
    fflush(stdout);  
    return 0;  
}  
void init(){  
    cout<<"请输入初始值"<<endl;  
    for(int x = 0; x < 9; x++){  
        for(int y = 0; y < 9; y++){            
            A[x][y] = 0;  
        }  
    }  
}  
int main(){  
//  init();  
//  A[2][5] = 8;  
    int n = 0;    
    cout<<"\n初始值\n";  
    n = count();  
    out_answer();  
    cout<<"\n答案\n";  
    f(n);  
    cout<<"\nhere end\n";  
    return 0;  
}  
