ciphertext = "CsgrgzmvksynytbmpgkuiswhgrejsxthvhvftkkxgrfsgxgtvoraexklaCfztabittvpltwpqgpvwuvxjemrvmmshpibzolmpgkuigjmnikljuzmpdzimjcensrahmzswpjgsiwqouevggbicnuvrzmvcckjmzpiccybxnmvknrgszipnyrastgqqujzetvitTnbtkzwqnjzeembehrakkuiusrtiykspdlpxhcwknvfwgvhpexbxoixgecrgzzspitpstbvcckfaoblqukrzkzoponvrmblgtihitiqgoiyimipkdvaxobcqfkuiublgrZaxkzeetzbrywzgrerxcwvmsnvprjiwnkeeimedlvimgmbveefmbmvgrfhxovkqfvagxgtveuceisivsrahziqreicvuwjdoorwcpmehzztrmqgnkpvexxqgintnqgrrfgsiwpuwzgltmetlpcixnietrfwazepcvnkgqrutracziqreivrmZiruknxowruwzyphmshcvaxxipkmgbvzireewnvswvgidcsxbeptzahkipknxfxnirgvvaxnmgteuvxxixknxfslbsfapGlkaifemrpuxqgnkfaotpclkrviwqrlvgirgxjeenxaziqfxbzkzroeegvkoynakvstblgasvpobcvoknbgvheoegvutieoebqokmptveeibmqnjglkifklzgczwogegvrlwvoakvstaiervgetlaklcrzkventvexnmrctleiunxtujgetlvgplgezqspYfhvlteiij0ne1ln49e7ea8v2si758816h1kh4e261"

def breakCipher(ciphertext):
    lower_letters = []
    for i in range(0, len(ciphertext)):
        if 97<=ord(ciphertext[i])<=122:
            lower_letters.append(i)
    ciphertext = ciphertext.upper()

    def calculate_IC_value(seq): # Function to calculate I.C. value of a fiven sequence
        sum_Fi = 0
        N = len(seq)
        for i in range(0, 26):
            Fi = seq.count(chr(i + 65))
            temp = Fi*(Fi-1)
            sum_Fi += temp
        IC = sum_Fi / (N * (N - 1))
        return IC

    def avg_IC(seq, key): # Function to calculate average value of I.C. for a particular key
        total_IC_value = 0
        for seq_number in range(0, key):
            sub_seq = ""
            for k in range(seq_number, len(seq), key):
                sub_seq += seq[k]
            total_IC_value += calculate_IC_value(sub_seq)
        avg_IC_value = total_IC_value / key
        return avg_IC_value

    def avg_IC_value_from_key1_to_key15(seq): # Function to calculate I.C. values for key 1-15
        seq = seq.upper()
        IC_values = []
        for key in range(1, 16):
            avg_IC_value = avg_IC(seq, key)
            IC_values.append(avg_IC_value)
        return IC_values

    def key_length(ciphertext):
        IC_Values = avg_IC_value_from_key1_to_key15(ciphertext)
        max_value = -1
        index = -1
        for i in range(0, 15):
            if IC_Values[i] > max_value:
                max_value = IC_Values[i]
                index = i
        return index + 1

    keyLength = key_length(ciphertext)

    probabilities = [0.082, 0.014, 0.028, 0.038, 0.131, 0.029, 0.02, 0.053, 0.064, 0.001, 0.004, 0.034, 0.025, 0.071, 0.08, 0.02, 0.0001, 0.068, 0.061, 0.105, 0.025, 0.009, 0.015, 0.002, 0.02, 0.001]
    
    def changeKey(s, key): # Function to change the sequence given a key
        temp = ""
        for i in s:
            if 65<=ord(i)<=90:
                x = ord(i) - key
                if x<65:
                    x = 91 - (key - (ord(i) - 65))
                temp += chr(x)
                s += temp
            else:
                temp+=i
        return temp

    def chi_squared_value(seq): # Function to calculate Chi-squared value of a sequence
        chi_val = 0
        n = len(seq)
        dict_seq = {}
        for i in seq:
            if 65<=ord(i)<=90:
                if i in dict_seq:
                    dict_seq[i] += 1
                else:
                    dict_seq[i] = 1
        for i in dict_seq:
            c = dict_seq[i]
            x = n*probabilities[ord(i) - 65]
            temp_val = ((c-x)**2)/x
            chi_val += temp_val
        return chi_val

    def key_index(seq): # Function to calculate the index where the smallest chi-squared value is measured
        smallest_val = 10**5
        smallest_val_index = 26
        chi_values = []
        for i in range(0, 26):
            temp_seq = changeKey(seq, i)
            temp_chi_val = chi_squared_value(temp_seq)
            if temp_chi_val < smallest_val:
                smallest_val = temp_chi_val
                smallest_val_index = i
            chi_values.append(temp_chi_val)
        return smallest_val_index

    def produce_key(ciphertext, keyLength): # Function which gives the key for the ciphertext given the ciphertext and key length
        key_val = ""
        n = len(ciphertext)
        for i in range(0, keyLength):
            seq = ""
            for j in range(i, n, keyLength):
                seq += ciphertext[j]
            keyIndex = key_index(seq)
            key_val += chr(65+keyIndex)
        return key_val

    key = produce_key(ciphertext, keyLength)

    import numpy as np
    def writeVignereTable(): # Function to create Vignere Table
        VignereTable = np.array([['']*26]*26)
        for i in range(0, 26):
            count = 0
            initial = 0
            for j in range(i, 26):
                VignereTable[i][initial] = chr(j+65)
                initial += 1
                count += 1
            if count!=26:
                for j in range(0, i):
                    VignereTable[i][j] = chr(i+j+65)
                ending = 0
                for j in range(26-i, 26):
                    VignereTable[i][j] = chr(ending + 65)
                    ending += 1
        return VignereTable

    VignereTable = writeVignereTable()

    def decrypt(ciphertext, key, vignereTable):
        n = len(ciphertext)
        plaintext = ""
        count_non_character = 0
        for i in range(0, n):
            if 65<=ord(ciphertext[i])<=90:
                row = ord(key[(i-count_non_character)%8]) - 65
                current_alphabet = ciphertext[i]
                for j in range(0, 26):
                    if vignereTable[row][j] == current_alphabet:
                        plaintext += chr(j + 65)
                        continue
            else:
                plaintext += ciphertext[i]
                count_non_character += 1
        return plaintext

    temp = list(decrypt(ciphertext, key, VignereTable))
    for i in lower_letters:
        temp[i] = temp[i].lower()
    plaintext = ""
    plaintext = plaintext.join(temp)
    return plaintext

print(breakCipher(ciphertext))