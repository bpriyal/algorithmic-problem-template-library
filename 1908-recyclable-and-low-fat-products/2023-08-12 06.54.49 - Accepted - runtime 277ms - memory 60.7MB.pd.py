import pandas as pd

def find_products(products: pd.DataFrame) -> pd.DataFrame:
    lowFatRecyclableProducts = products[(products['low_fats'] == 'Y') & (products['recyclable'] == 'Y')]
    return lowFatRecyclableProducts[['product_id']]