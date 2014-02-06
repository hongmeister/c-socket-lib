/**
 * Macros for creating classes and methods, and instantiating/releasing objects
 *
 * @author 	Daniel Hong
 */

#ifndef _DSH_CLASS_H_
#define _DSH_CLASS_H_

// Define a class
#define CLASS( _NAME_, _BODY_ ) typedef struct _NAME_ { _BODY_ } _NAME_

// Define member functions
#define FUNC(_TYPE_, _NAME_, _PARAM_) _TYPE_ (*_NAME_) _PARAM_

// Instantiate a class
#define NEW(_CLASS_) ((_CLASS_*)malloc(sizeof(_CLASS_)))

// Release a class object from memory
void release(void *);

#endif /* _DSH_CLASS_H_ */
