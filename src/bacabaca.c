/*
 * bacabaca.c
 *
 *  Created on: 5 oct. 2019
 *      Author: utnso
 */
#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<semaphore.h>

pthread_t tid[4];
sem_t semA;
sem_t semB;
sem_t semC;
sem_t semBA;
sem_t semCA;

void* printA(void *arg) {
    unsigned int i = 1;
    for(i=1; i<=(300);i++){
    	//usleep(20000);
    	sem_wait(&semA);
    	printf("\nAAAA n° %d", i);
    	sem_post(&semC);
    	sem_post(&semB);
    }
    return NULL;
}

void* printB(void *arg) {
	unsigned int i = 1;
    for(i=1; i<=(300);i++){
    	//usleep(20000);
    	sem_wait(&semBA);
    	sem_wait(&semB);
    	printf("\nBBBB n° %d", i);
    	sem_post(&semA);
    	sem_post(&semCA);
    }
    return NULL;
}

void* printC(void *arg) {
	unsigned int i = 1;
    for(i=1; i<=(300);i++){
    	//usleep(20000);
    	sem_wait(&semCA);
    	sem_wait(&semC);
    	printf("\nCCCC n° %d", i);
    	sem_post(&semA);
    	sem_post(&semBA);
    }
    return NULL;
}

int main(void) {
    int err;
    sem_init(&semA,0,0);
    sem_init(&semB,0,1);
    sem_init(&semC,0,0);
    sem_init(&semBA,0,1);
    sem_init(&semCA,0,0);

    err = pthread_create(&(tid[0]), NULL, printB, NULL);
    if (err != 0){
    	printf("\nHubo un problema al crear el thread printB:[%s]", strerror(err));
    	return err;
    }
    printf("\nPrintB en ejecución\n");

    err = pthread_create(&(tid[1]), NULL, printA, NULL);
    if (err != 0){
    	printf("\nHubo un problema al crear el thread printA:[%s]", strerror(err));
    	return err;
    }
    printf("\nPrintA1 en ejecución\n");

    err = pthread_create(&(tid[2]), NULL, printC, NULL);
    if (err != 0){
    	printf("\nHubo un problema al crear el thread printC:[%s]", strerror(err));
    	return err;
    }
    printf("\nPrintC en ejecución\n");

    err = pthread_create(&(tid[3]), NULL, printA, NULL);
    if (err != 0){
       	printf("\nHubo un problema al crear el thread printA:[%s]", strerror(err));
       	return err;
    }
    printf("\nPrintA2 en ejecución\n");

    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
    pthread_join(tid[2], NULL);
    pthread_join(tid[3], NULL);

    sem_destroy(&semA);
    sem_destroy(&semB);
    sem_destroy(&semC);
    sem_destroy(&semBA);
    sem_destroy(&semCA);

    printf("\n Listo!! \n");
    return 0;
}
