#include <Python.h>
/**
 * print_python_list_info - prints some basic info about Python lists
 * @p: a Python object
 *
 * Return: nothing
 */
void print_python_list_info(PyObject *p)
{
	int mem, index, len;

	/* each element of list is a py onject */
	PyObject *list_item;

	/* the length of the list */
	len = Py_SIZE(p);

	/* memory allocated to each list */
	mem = ((PyListObject *)p)->allocated;

	printf("[*] Size of Python List = %d\n", len);
	printf("[*] Allocated = %d\n", mem);

	for (index = 0; index < len; index++)
	{
		/* get each element from list */
		list_item = PyList_GetItem(p, index);

		/* print the element's type */
		printf("Element %d: %s\n", index, Py_TYPE(list_item)->tp_name);
	}
}
