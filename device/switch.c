/*************************************************************************
 *
 *  JSIM Release 2.0 10/24/92
 *
 *  JSIM is a simulator for circuits containing Josephson Junctions.
 *
 *  Author:         Emerson Fang, 1991
 *                  University of California, Berkeley
 *                  Dept. of Electrical Engineering and Computer Sciences
 *                  Cryoelectronics Group, Professor Ted Van Duzer
 *                  
 *
 *  Cleanup Crew:   Jay Fleischman    (jef@swordfish.berkeley.edu)
 *                  Steve Whiteley    (stevew@landau.conductus.com)
 *
 *  This Device:    Jon Collins	      (jon.collins@npl.co.uk)
 *
 *************************************************************************/

#include "jsim_n.h"
#include "extern_n.h"


void
read_switch() {

long name;
int bad_dev = FALSE;

  read_error = read_long(nodeptr, "plus node", FALSE);
  read_error = read_long((nodeptr+1), "minus node", FALSE); 
//do I need this one? 
// read_error = read_double(dataptr, "switch value", FALSE);

if (read_error != OK) {
    printf("## Error -- bad switch definition\n");
    no_go = TRUE;
    bad_dev = TRUE;
}

read_error = read_string("");

if (read_error == OK) {
	if (get_string_keyword(tempstring) == IC) {
		read_error = read_double(dataptr+1, "initial condition", FALSE);
	} else {
		printf("## Warning -- illegal keyword %s\n", tempstring);
	}
}

if (bad_dev == FALSE) {
	if (current_sub_def == NULL) {
		name = add_realname(dev_name);
		switch_to_devlist(name, SWITCH, nodeptr, dataptr);
	} else {
		switch_to_deftree(dev_name, SWITCH, nodeptr, dataptr);
	}

} /* read switch */

//this is a device *, but I'm making it a void for now
//device * 
void switch_to_devlist(name, type, nodeptr, intptr, dataptr)

long name;
int type;
long *nodeptr;
long *intptr;
double *dataptr;
{
//I'm into behaviours now
}

void switch_to_deftree(name, type, nodeptr, intptr, dataptr)

char *dev_name;
int type;
long *nodeptr;
long *intptr;
double *dataptr;
{
}
