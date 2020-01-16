/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   sched.h
 * Author: shrik
 *
 * Created on 20 September, 2019, 9:49 PM
 */

#ifndef SCHED_H
#define SCHED_H

int sched_class;

void setschedclass(int);
int getschedclass();
int pick_nextproc(int);
int getproc(int);
int find_next_pro();
void print_queue();
#endif /* SCHED_H */

