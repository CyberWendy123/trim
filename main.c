// trim function  
#include <stdio.h> 
#include <stdlib.h> 
#include <ctype.h> 
#include <string.h> 

size_t *trim(char *out, size_t len, const char*str){
	if(len == 0)
		return 0; 

	const char *end; 
	size_t out_size; 

	// Trim leading space 
	while(isspace((unsigned char)*str)) str++; 

	if(*str == 0){ //all spaces? 
		*out = 0; 
		return 1; 
	}

	// trim trailing space 
	end = str + strlen(str) - 1; 
	while(end > str && isspace ((unsigned char)*end)) end--;  
	end++; 

	// set output size to minimum of trimmed string length and buffer 
	out_size = (end - str) < len-1 ? (end - str) : len -1; 

	//copy trimmed string and add null terminator 
	memcpy(out, str, out_size); 
	out[out_size] = 0; 

	return out_size; 
}

int main(){
	int lenValue = 255; 
	char *testStr = "     trim this    "; //this is read only... 
	char *final = malloc(100*sizeof(char)); //out value has to malloc otherwise it will segment fault 

	trim(final, lenValue, testStr); 

	printf("%s\n", final);

	free(final); 
	return 0; 
}