//
//  tictactoe.c
//  
//
//  Created by Ahmet Mihca Aydin on 11.04.2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <stdbool.h>
typedef struct data {
    int num;
    char **arr;
} data;

pthread_mutex_t lock;

int check_winner(data *thread_data,char c) {
    bool flag = true;
    
    // check for rows
    for(int i = 0; i < thread_data->num; i++) {
        flag = true;
        for(int j = 0; j < thread_data->num; j++) {
            if(thread_data->arr[i][j]!=c)
                flag = false;
        }
        if(flag)
            return 1;
    }
    
    // check for column
    for(int i = 0; i < thread_data->num; i++) {
        flag = true;
        for(int j = 0; j<thread_data->num; j++) {
            if(thread_data->arr[j][i]!= c)
                flag = false;
        }
        if(flag)
            return 1;
    }

    // check for back diagonal "\"
    flag = true;
    for(int i = 0; i<thread_data->num; i++)
        if(thread_data->arr[i][i] != c)
            flag = false;
    if(flag)
        return 1;
    
    // check for forward diagonal "/"
    flag = true;
    for(int i = 0, j = thread_data->num - 1; i<thread_data->num; i++, j--)
        if(thread_data->arr[i][j] != c)
            flag = false;
    if(flag)
        return 1;
    return 0;
}

int check(data *thread_data) {
    // Return 1 for Winner X 
    // Return 2 for Winner O
    // Return 3 For TIE
    // Return 0 ELSE
    
    if(check_winner(thread_data,'x'))
        return 1;
    
    if(check_winner(thread_data,'o'))
        return 2;
    
    bool flag = true;
    for(int i=0;i<thread_data->num;i++)
        for(int j=0;j<thread_data->num;j++)
            if(thread_data->arr[i][j]==' ')
                flag = false;
    if(flag)
        return 3;
    return 0;
}

void *thread_fun_1(void *arg) {
    
    pthread_mutex_lock(&lock);
    data *thread_data = (data*)arg;
    int n = thread_data->num;
    
    while(true) {
        
        srand(time(NULL));
        int random = rand();
        random %= n*n;
        if(random < 0)
            random *= -1;
        int r = random/n;
        int c = random%n;
        
        if(thread_data->arr[r][c]==' ') {
            printf("Player x played on: (%d,%d)\n",r,c);
            thread_data->arr[r][c] = 'x';
            break;
        }
    }

    pthread_mutex_unlock(&lock);
    pthread_exit(NULL);
    return NULL;
}

void *thread_fun_2(void *arg) {
    pthread_mutex_lock(&lock);
    data *thread_data = (data*)arg;
    int n = thread_data->num;
    
    while(true) {
        srand(time(NULL));
        int random = rand();
        random %= n*n;
        
        if(random < 0)
            random *= -1;
        int r = random/n;
        int c = random%n;
        
        if(thread_data->arr[r][c]==' ') {
            printf("Player o played on: (%d,%d)\n",r,c);
            thread_data->arr[r][c] = 'o';
            break;
        }
    }

    pthread_mutex_unlock(&lock);
    pthread_exit(NULL);
    return NULL;
}

void *main_thread_fun(void *arg) {
    
    if (pthread_mutex_init(&lock, NULL) != 0) {
        printf("mutex init has failed\n");
        return NULL;
    }

    int *n = (int*) arg;
    data *thread_data = (data*)malloc(sizeof(data));
    thread_data->num = *n;

    thread_data->arr = (char **)malloc(*n * sizeof(char *));

    for (int i = 0; i < *n; i++)
        thread_data->arr[i] = (char *)malloc(*n * sizeof(char));

    for(int i = 0; i <*n; i++)
        for(int j = 0; j<*n; j++)
            thread_data->arr[i][j] = ' ';

    pthread_t pthread_child_1;
    pthread_t pthread_child_2;

    bool flag = true;
    int k = 0;
    printf("Board Size: %dx%d\n",*n,*n);

    while(true) {
        
        int error = 0;
        if(flag) {
            error = pthread_create(&pthread_child_1, NULL, &thread_fun_1, (void*)thread_data);
            pthread_join(pthread_child_1, NULL);
        }
        
        else {
            error = pthread_create(&pthread_child_2, NULL,&thread_fun_2, (void*)thread_data);
            pthread_join(pthread_child_2, NULL);
        }

        if(error!=0) {
            printf("creation fails\n");
            pthread_exit(NULL);
            return NULL;
        }

        k = check(thread_data);
        
        if(k)
           break;
        flag = !flag;
    }

    pthread_mutex_destroy(&lock);
    
    printf("Game end\n");
    
    if(k == 1)
        printf("Winner is X\n");
    else if(k == 2)
        printf("Winner is O\n");
    else
        printf("It is a tie\n");
    
    for(int i = 0; i < *n; i++) {
        for(int j = 0; j < *n; j++)
            printf("[%c]",thread_data->arr[i][j]);
        printf("\n");
    }

    pthread_exit(NULL);
    return NULL;
}

int main(int argc, char const *argv[]) {
    
    if(argc < 2) { // FOR SAFETY
        printf("You did not specify the arguments or parameters!!");
        exit(0);
    }

    int n = atoi(argv[1]);
    pthread_t pthread;
    pthread_create(&pthread, NULL, &main_thread_fun, (void*)&n);
    pthread_join(pthread,NULL);
    pthread_exit(NULL);
    return 0;
}


