#include<iostream>
using namespace std;
struct StuScores {
  int index;
  int grades;
}stuScores[5];
int main() {
  string gradeClass[] = {"优秀", "较好", "良"}; 
  string courseName[] = {"语文", "数学", "英语", "物理", "化学"}; 
  string name[] = {"小王", "小明", "小丽", "小花", "小月"}; 
  int grade[5][5] = {        //学生各科成绩表 
    70, 95, 92, 80, 87,
    81, 82, 85, 91, 95,
    85, 88, 65, 72, 63,
    71, 74, 63, 77, 64, 
    95, 92, 96, 93, 90  
  };
  
  int courseSituation[5][3] = {0};//各科优良情况表 
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      stuScores[i].grades += grade[i][j];//统计每个学生总分 
      stuScores[i].index = i;
      //统计各个科目成绩优良情况 
      if (grade[j][i] >= 90) {
        courseSituation[i][0]++;
      } else if (grade[j][i] >= 80) {
        courseSituation[i][1]++;
      } else if (grade[j][i] >= 70){
        courseSituation[i][2]++;
      }
    }
  }
  //打印，查看每个同学总分 
  for (int i = 0; i < 5; i++) cout << name[stuScores[i].index] << stuScores[i].grades << endl;
  //int rank[3]; 
  //筛选前三名的同学 
  for (int i = 0; i < 3; i++) {
    int index = i; 
    for (int j = i + 1; j < 5; j++) {
      if (stuScores[j].grades > stuScores[index].grades) index = j;
    }
    //rank[i] = stuScores[index].index;
    swap(stuScores[index], stuScores[i]);
  }
  //打印排名 
  for (int i = 0; i < 3; i++) {
    cout << "第" << i + 1 << "名" << ":" << name[stuScores[i].index] << " "; 
  }
  cout << endl;
  for (int i = 0; i < 5; i++) {//打印各科情况 
    cout << courseName[i] << ":";
    for (int j = 0; j < 3; j++) {
      cout << gradeClass[j] << courseSituation[i][j] << " ";
    }
    cout << endl; 
  }
}
