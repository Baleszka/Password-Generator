import random

characters=['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
numbers=[1,2,3,4,5,6,7,8,9,0]
special=['@','&','$','%','_','[',']','<','>','#']
print("\nWelcome to the password generator!\n")
print("Follow the instructions to generate a password!\n")
print("----------------------------------------------------------\n")
while True:
    try:
        passlen=int(input("Enter the length of password: "))
        print("\nThe values you will be prompted to choose must add up to the length of the password!\n")
        charamt=int(input("Enter the amount of characters you want your password to have: "))
        numamt=int(input("\nEnter the amount of numbers you want your password to have: "))
        specamt=int(input("\nEnter the amount of special characters you want your password to have: "))
        if charamt+numamt+specamt!=passlen:
            print("!!!The values you entered do not add up to the length of the password!!!\n")
            continue
        else:
            password=""
            for i in range(charamt):
                password+=random.choice(characters)
            for i in range(numamt):
                password+=str(random.choice(numbers))
            for i in range(specamt):
                password+=random.choice(special)
            shuffle=str(input("\nDo you want to shuffle the password? (y/n): ")).lower()
            if shuffle=="y":
                password=''.join(random.sample(password,len(password)))
                print("\n----------------------------------------------------------\n")
                print("Your password is: "+password)
                break
            elif shuffle=="n":
                print("Your password is: "+password)
                break
            else:
                print("Invalid input!")
                continue
    except ValueError:
        print("Please enter an interger!")