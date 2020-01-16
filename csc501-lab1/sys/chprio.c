/* chprio.c - chprio */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <q.h>
#include <stdio.h>
#include "lab1.h"
#include "sched.h"

/*------------------------------------------------------------------------
 * chprio  --  change the scheduling priority of a process
 *------------------------------------------------------------------------
 */
SYSCALL chprio(int pid, int newprio)
{
	STATWORD ps;    
	struct	pentry	*pptr;

	disable(ps);
	if (isbadpid(pid) || newprio<=0 ||
	    (pptr = &proctab[pid])->pstate == PRFREE) {
		restore(ps);
		return(SYSERR);
	}
	pptr->pprio = newprio;
	/*In case of exponential scheduler, when priority changes, you need to refresh the 
 	  ready queue as the exponential_distribution depends on the priority of processes*/ 
	if(sched_class == EXPDISTSCHED)
	{
		dequeue(pid);
		insert(pid, rdyhead, pptr->pprio);
	}	
	restore(ps);
	return(newprio);
}
