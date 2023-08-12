import pandas as pd

def find_customers(customers: pd.DataFrame, orders: pd.DataFrame) -> pd.DataFrame:
    custWhoNeverOrder = customers[~customers['id'].isin(orders['customerId'])]
    return custWhoNeverOrder[['name']].rename(columns={'name' : 'Customers'})