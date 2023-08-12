import pandas as pd

def big_countries(world: pd.DataFrame) -> pd.DataFrame:
    # Filter out by condition
    bigCountries = world[(world['area'] >= 3000000) | (world['population'] >= 25000000)]
    # Filter required columns
    bigCountries = bigCountries[['name', 'population', 'area']]
    return bigCountries