import pandas as pd
import glob

if __name__=="__main__":
    files = glob.glob("/home/sanial/PycharmProjects/stock/ETFs/*.txt")
    for file_name in files:
        x = pd.read_csv(file_name, low_memory=False)
        print(x.head())
