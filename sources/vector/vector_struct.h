#ifndef VECTOR_STRUCT_H
#define VECTOR_STRUCT_H

struct 	Vector{
	struct VectorItem**items;

	size_t	vector_index;
	size_t	vector_length;
};

#endif
