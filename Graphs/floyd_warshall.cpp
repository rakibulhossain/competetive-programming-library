for(int k=1; k<=n; k++)
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            if(cost[i][j]>cost[i][k]+cost[k][j])
                cost[i][j]=cost[i][k]+cost[k][j];

