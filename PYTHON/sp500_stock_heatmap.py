# Visualizing the stock correlation heatmap for companies listed in S&P 500.

from typing import Sized
import bs4 as bs
import requests
import pandas as pd
import numpy as np
import yfinance as yf
import matplotlib.pyplot as plt
from matplotlib import style
import datetime as dt
import os
import plotly.express as px

style.use('ggplot')

# Finding the Symbols (ticker) for a company
def sp500_tickers():
    resp = requests.get('https://en.wikipedia.org/wiki/List_of_S%26P_500_companies')
    soup = bs.BeautifulSoup(resp.text, "lxml")
    table =soup.find('table', {'class': 'wikitable sortable'})
    tickers = []
    for row in table.findAll('tr')[1: ]:
        ticker = row.findAll('td')[0].text
        ticker = ticker[:-1]
        tickers.append(ticker)

    # with open("sp500tickers.pickle", "wb") as f:
    #     pickle.dump(ticker, f)
    sp500 = pd.DataFrame({'tickers': tickers})
    # getting the tickers (symbols) of companies in S&P 500
    sp500.to_csv('sp500tickers.csv')
    
    print(tickers)
    return tickers

def get_stock_data():
    # time period to get the stock data
    start = dt.datetime(2000,1,1)
    end = dt.datetime(2016,12,31)
    sp500 = pd.read_csv('sp500tickers.csv')
    
    print(sp500['tickers'][:20])
    # making a directory for each ticker to store each company's stock data
    if not os.path.exists('stock_dfs'):
        os.makedirs('stock_dfs')

    # Initially getting the stock data for first 20 companies in S&P 500
    for ticker in sp500['tickers'][:20]:
        if not os.path.exists('stock_dfs/{}.csv'.format(ticker)):
            df = yf.download(ticker, start, end)
            df.to_csv('stock_dfs/{}.csv'.format(ticker))
        else:
            print('Already have {}'.format(ticker))

# combining all the dataFrames created into 1 DataFrame. Using only the Adj Close column

def compile_data():
    sp500 = pd.read_csv('sp500tickers.csv')
    main_df = pd.DataFrame()
    for count, ticker in enumerate(sp500['tickers'][:20]):
        df = pd.read_csv('stock_dfs/{}.csv'.format(ticker))
        df.set_index('Date', inplace=True)
        df.rename(columns = {'Adj Close': ticker}, inplace=True)
        df.drop(['Open', 'High', 'Low', 'Volume', 'Close'], axis=1, inplace=True)
        if main_df.empty:
            main_df = df
        else:
            main_df = main_df.join(df, how='outer')

        if count%10 == 0:
            print(count)
    print(main_df.head())
    main_df.to_csv('sp500_joint_adj_closes.csv')


######################## Getting the relations between the companies between time frames
# like 10, 12, 15 years. How these companies react to each other. basically correlation
# between the companies

def visualize_data():
    sp500_tickers()
    get_stock_data()
    compile_data()
    
    df = pd.read_csv('sp500_joint_adj_closes.csv')
    # df['AMD'].plot() # plots just the AMD Adj Close
    # making a correlation data graph
    df_corr = df.corr()

    data = df_corr.values

    ########### Plotting heatmap with matplotlib #############
    fig = plt.figure()
    ax = fig.add_subplot(1,1,1)
    heatmap = ax.pcolor(data, cmap = plt.cm.RdYlGn)
    fig.colorbar(heatmap)
    ax.set_xticks(np.arange(data.shape[0]) + 0.5, minor=False)
    ax.set_yticks(np.arange(data.shape[1]) + 0.5, minor=False)
    ax.invert_yaxis()
    ax.xaxis.tick_top()
    column_labels = df_corr.columns
    row_labels = df_corr.index

    ax.set_xticklabels(column_labels)
    ax.set_yticklabels(row_labels)
    plt.xticks(rotation=90)
    heatmap.set_clim(-1, 1)     # limits of the color, so -1 is minimum and 1 is maximum
    plt.tight_layout()
    plt.show()

    ######## Plotting heatmap with Plotly ###############
    # Interactive plot

    fig2 = px.imshow(data,
                    x = df_corr.columns,
                    y = df_corr.columns,
                    zmin=-1,
                    zmax=1)

    fig2.update_xaxes(side="top")
    fig2.show()

visualize_data()
