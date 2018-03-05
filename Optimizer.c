/*
 *********************************************
 *  314 Principles of Programming Languages  *
 *********************************************
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "InstrUtils.h"
#include "Utils.h"

int main()
{
	Instruction *head;

	head = ReadInstructionList(stdin);
	if (!head) {
		WARNING("No instructions\n");
		exit(EXIT_FAILURE);
	}

    Instruction *current, *previous, *next;
    current = head;
    previous = head->prev;
    next = head->next;
    //Do this while current and next exist. AKA not NULL
    while(current && next){
        if (previous && previous->opcode == LOADI && current && current->opcode == LOADI){
            switch(next->opcode){
                //Adding
                case ADD:
                    current->field1 = next->field1;
                    current->field2 = next->field2;
                //Subtracting
                case SUB:
                    current->field1 = next->field1;
                    current->field2 = current->field2 - previous->field2;
                //Multiplying
                case MUL:
                    current->field1 = next->field1;
                    current->field2 = current->field2 * previous->field2;

                    current->next = next->next;
                    current->next->prev = current;
                    current->prev = previous->prev;
                    current->prev->next = current;
                    //FREEDOM
                    free(previous);
                    free(next);
                default:
                    break;
            }
        }
        //Move on with the list
        current = current->next;
        previous = current->prev;
        next = current->next;
    }

	if (head) {//Wait this doesn't actually do anything?? Head is always true
		PrintInstructionList(stdout, head);
		DestroyInstructionList(head);
	}
	return EXIT_SUCCESS;
}

