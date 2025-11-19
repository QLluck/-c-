 if (i == 0)
        {
            for (int j = 0; j <=sum-1;j++)
            {
                cout << j << ' ';
            }

        }
        else if(i==n)
        {
            for (int j = x; j >= x-sum+1; j--)
            {
                cout << j << ' ';
            }
        }
        else 
        { for (int j = st; j <= st + sum - 1; j++)
            cout << j << ' ';
        }