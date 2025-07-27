

int main() {
    int n =8;
    int a[8] ={1};
    int s = 0; 
    for (int i = 0; i < n; i += 4) {
        s += a[i];
    }
    return 0;
}