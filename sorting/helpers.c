void printArray(int size, int array[size]) {
	int i, j;
	for(i=0; i<size; i++) {
		printf(" %d ", array[i]);
	}
}

void getArray(int size, int array[size]) {
	int i;
	for(i=0; i<size; i++) {
		scanf("%d", &array[i]);
	}
}
