#include<stdio.h>

int full= 0, empty= 5, mutex= 1, x=0;
int wait(int* s){
    s--;
}

int signal(int* s){
    s++;
}

void producer(){
    mutex = wait(mutex);
    full= signal(&full);
    empty= wait(&empty);
    x++;
    printf("Producer produces %d item\n", x);
    mutex= signal(mutex);
}

void consumer(){
    mutex = wait(mutex);
    full= wait(&full);
    empty= signal(&empty);
    printf("Consumer consumes %drd item\n",x);
    x--;
    mutex= signal(mutex);
}

int main(){
    int ch;
    printf("1-Producer\n2-Consumer\n3-Exit\n");
    while(1){
        scanf("%d", &ch);
        switch(ch){
        case 1:
            if(mutex== 1 && empty>0){
                producer();
            }
            else{
                printf("Buffer is full");
            }
            break;
        case 2:
            if(mutex== 1 && full>0){
                consumer();
            }
            else{
                printf("Buffer is empty");
            }
            break;
        case 3:
            exit(0);
        }
    }
}

/*Output - 
1-Producer
2-Consumer
3-Exit
1
Producer produces 1 item
1
Producer produces 2 item
1
Producer produces 3 item
1
Producer produces 4 item
1
Producer produces 5 item
2
Consumer consumes 5rd item
2
Consumer consumes 4rd item
2
Consumer consumes 3rd item
2
Consumer consumes 2rd item

2
Consumer consumes 1rd item
3
*/
