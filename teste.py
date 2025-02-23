num = 3
soma = 0    

while( num >= 0 & num <= 499):
    num += 3 
    if(num % 2 != 0): # Se o número for ímpar
        print(num)
    else:
        soma += num 
        print(soma)
    
