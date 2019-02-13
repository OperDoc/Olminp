void allserch(int n)/*O(2^n)*/{
    for(long long i = 0; i < (1<<n); i++){
        for(int j = 0; j < n; j++)
            if(i & (1<<j)) cout << 1;
            else cout << 0;
        cout << '\n';
    }
}
