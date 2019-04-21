def reverse(value):
    if value<0:
        value=str(value)[1:]
    else:
        value=str(value)
    length=len(value)
    return value[::-1]



if __name__ == "__main__":
    print(reverse(-1223))
