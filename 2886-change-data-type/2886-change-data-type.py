import pandas as pd

def convert(x):
    return int(x)

def changeDatatype(students: pd.DataFrame) -> pd.DataFrame:
    students["grade"] = students["grade"].apply(convert)
    return students
    