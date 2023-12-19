int* create_arr()
{
	return new int[10];
}
int main(int argc, char** argv)
{
	int* external_arr = create_arr();
	delete[] external_arr;
	return 0;
}
