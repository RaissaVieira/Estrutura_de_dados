while True:
    try:
        quantidade = int(input('Quantas vezes você deseja fazer este procedimento? '))
        break
    except ValueError:
        print("Oops!  That was no valid input.  Try again...\n")

a = 0

for a in range(quantidade):
    temperaturas = str(input('\npor favor, entre com a unidade de temperatura desejada:celsius(c),fahrenheit(f),kelvin(k),rankine(ra),réaumur(re): '))

    if temperaturas == "c":
        while True:
            try:
                c= float(input('Informe a temperatura em °C: '))
                break
            except ValueError:
                print("Oops!  That was no valid input.  Try again...\n")
        
        f= c*1.8 + 32
        k= c + 273.15
        ra= (c + 273.15)*1.8
        re= c*0.8
        print('A temperatura de {}°C corresponde a {}°F!'.format(c,f))
        print('A temperatura de {}°C corresponde a {}°K!'.format(c,k))
        print('A temperatura de {}°C corresponde a {}°Ra!'.format(c,ra))
        print('A temperatura de {}°C corresponde a {}°Re!\n'.format(c,re))

    elif temperaturas=="f":
        while True:
            try:
                f= float(input('Informe a temperatura em °F: '))
                break
            except ValueError:
                print("Oops!  That was no valid input.  Try again...\n")
        c=(f - 32)/1.8
        k=(f + 459.67)/ 1.8
        ra= f + 459.67
        re= (f - 32)*4/9
        print('A temperatura de {}°F corresponde a {}°C!'.format(f,c))
        print('A temperatura de {}°F corresponde a {}°K!'.format(f,k))
        print('A temperatura de {}°F corresponde a {}°Ra!'.format(f,ra))
        print('A temperatura de {}°F corresponde a {}°Re!\n'.format(f,re))

    elif temperaturas=="k":
        while True:
            try:
                k= float(input('Informe a temperatura em °K: '))
                break
            except ValueError:
                print("Oops!  That was no valid input.  Try again...\n")

        c= k - 273.15
        f= k*1.8 - 459.67
        ra= k*1.8 
        re= (k-273.15)*0.8
        print('A temperatura de {}°K corresponde a {}°C!'.format(k,c))
        print('A temperatura de {}°K corresponde a {}°F!'.format(k,f))
        print('A temperatura de {}°K corresponde a {}°Ra!'.format(k,ra))
        print('A temperatura de {}°K corresponde a {}°Re!\n'.format(k,re))

    elif temperaturas=="ra":
        while True:
            try:
                ra= float(input('Informe a temperatura em °Ra: '))
                break
            except ValueError:
                print("Oops!  That was no valid input.  Try again...\n")
        c= (ra - 491.67)/1.8
        f= ra - 459.67
        k= ra/1.8
        re= (ra - 491.67)*4/9
        print('A temperatura de {}°Ra corresponde a {}°C!'.format(ra,c))
        print('A temperatura de {}°Ra corresponde a {}°F!'.format(ra,f))
        print('A temperatura de {}°Ra corresponde a {}°K!'.format(ra,k))
        print('A temperatura de {}°Ra corresponde a {}°Re!\n'.format(ra,re))

    elif temperaturas=="re":
        while True:
            try:
                re= float(input('Informe a temperatura em °Re: '))
                break
            except ValueError:
                print("Oops!  That was no valid input.  Try again...\n")
        c= re/0.8
        f= re*9/4 + 32
        k= re*1.25 + 273.15
        ra= re*9/4 + 491.67
        print('A temperatura de {}°Re corresponde a {}°C!'.format(re,c))
        print('A temperatura de {}°Re corresponde a {}°F!'.format(re,f))
        print('A temperatura de {}°Re corresponde a {}°K!'.format(re,k))
        print('A temperatura de {}°Re corresponde a {}°Ra!\n'.format(re,ra))
    
    a+=1