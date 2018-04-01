
struct Dynamic_generic_stack{
	int capacity;
	int top;
	void **array;			//an array of void pointers
	size_t size;			//size of each element
};

struct Dynamic_generic_stack *createStack(size_t);
int isStackFull(struct Dynamic_generic_stack * S);
int isStackEmpty(struct Dynamic_generic_stack *S);
void doubleStack(struct Dynamic_generic_stack *S);
void push(struct Dynamic_generic_stack *S,void* x);
void* top(struct Dynamic_generic_stack *S);
void* pop(struct Dynamic_generic_stack *S);
void deleteStack(struct Dynamic_generic_stack *S);
