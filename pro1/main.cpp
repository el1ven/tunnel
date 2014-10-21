//
//  main.cpp
//  pro1
//
//  Created by el1ven on 14-6-6.
//  Copyright (c) 2014年 el1ven. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

int maxHeight(queue<int> q){
    stack<int> max;
    max.push(q.front());
    q.pop();
    while(!q.empty()){
        if(q.front() >= max.top()){
            max.push(q.front());
            q.pop();
        }else{
            q.pop();
        }
    }
    return max.top();
}

int main(){
    int m = 0;//总的操作次数
    queue<int> result;//结果输出队列
    while(cin>>m){
        queue<int> q = {};//初始化队列
        result = {};
        char opt = ' ';//操作种类
        int height = 0;//列车高度
        for(int i = 0; i < m; i++){
            cin>>opt;
            if(opt == 'E'){
                cin>>height;
                q.push(height);//遇到E, 有火车进入隧道
            }else if(!q.empty() && opt == 'D'){
                result.push(q.front());
                q.pop();
            }else if(opt == 'M'){//遇到M，查询列车的最大高度
                result.push(maxHeight(q));
            }
        }
        
        while(!result.empty()){//对结果进行输出
            cout<<result.front()<<endl;
            result.pop();
        }
    }
    
    return 0;
}



