int firstMissingPositive(int* arr, int Size){
for (int i = 0; i < Size; i++) {
        while (arr[i] > 0 && arr[i] <= Size && arr[arr[i] - 1] != arr[i]) {
     int temp = arr[i];
    arr[i] = arr[temp - 1];
     arr[temp - 1] = temp;
        }
    }
for (int i = 0; i < Size; i++){
   if (arr[i] != i + 1)
    return i + 1;
    }

    return Size + 1;
}