import os
import datetime as dt
tanggal=dt.date.today()
while True:
 os.system("cls")
 print("\n")
 print("\n")
 print("\n")
 print("-----------------------------------------------------------------")
 print("|                                                               | ")
 print("|\t   ######### HOTEL WARNA MERAHH #########               |")
 print("|                                                               |")
 print("-----------------------------------------------------------------")
 print("\n")
 pemesan = input("MASUKKAN NAMA PEMESAN: ")
 print("NAMA PEMESAN : ", pemesan)
 
#fungsi kamar
 def kamar():
  global total1
  global menginap
  global jenis1
  print ("\n~~~~PILIH KAMAR~~~~")
  print ("1. Standar Room(STD) /Malam      = Rp.300000")
  print ("2. Superior Room(SUP) /Malam     = Rp.387000")
  print ("3. Delux Room(DLX) /Malam        = Rp.420000")
  print ("4. Junior Suit Room(JRST) /Malam = R.p490000")
  print ("5. Suit Room(STE) /Malam         = Rp.550000")
  print ("6. Presidential Suit(VVIP)/Malam = Rp.720000")
 
  nomor = int(input("MASUKKAN PILIHAN KAMAR : "))
  menginap = int(input("BERAPA MALAM        : "))
 
  if nomor==1:
   total1=menginap*300000
   print (menginap," MALAM KAMAR STD Rp.", total1)
   jenis1=("Standar Room(STD)")
  elif nomor==2:
   total1=menginap*387000
   print (menginap," MALAM KAMAR SUP Rp.", total1)
   jenis1=("Superior Room(SUP)")
  elif nomor==3:
   total1=menginap*420000
   print (menginap," MALAM KAMAR DLX Rp.", total1)
   jenis1=("Delux Room(DLX) ")
  elif nomor==4:
   total1=menginap*490000
   print (menginap," MALAM KAMAR JRST Rp.", total1)
   jenis1=("Junior Suit Room(JRST) ")
  elif nomor==5:
   total1=menginap*550000
   print (menginap," MALAM KAMAR STE Rp.", total1)
   jenis1=("Suit Room(STE)")
  elif nomor==6:
   total1=menginap*720000
   print (menginap," MALAM KAMAR VVIP Rp.", total1)
   jenis1=("Presidential Suit(VVIP)")
  else:
   print("Pilihan Kamar Tidak Ditemukan!")
 kamar()
 
#fungsi makanan
 def makanan():
  global total3
  global jenis3
  global porsi
 print("\n~~~~BreakFast~~~~")
 print("\n****Makanan****")
 print("1. MAKAN 1 = Rp.10000")
 print("2. MAKAN 2 = Rp.13000")
 print("3. MAKAN 3 = Rp.20000")
 print("4. MAKAN 4 = Rp.15000")
 print("5. MAKAN 5 = Rp.0")
 nomor=int(input("MASUKKAN PILIHAN Makanan: "))
 porsi= int(input("Berapa Porsi: "))
 if nomor==1:
  total3=porsi*10000
  print(porsi," MAKAN 1 Rp.", total3)
  jenis3=("MAKAN 1")
 elif nomor==2:
  total3=porsi*12000
  print(porsi," MAKAN 2 Rp.", total3)
  jenis3=("MAKAN 2")
 elif nomor==3:
  total3=porsi*13000
  print(porsi," MAKAN 3 Rp.", total3)
  jenis3=("MAKAN 3")
 elif nomor==4:
  total3=porsi*14000
  print(porsi," MAKAN 4 Rp.", total3)
  jenis3=("MAKAN 4")
 elif nomor==5:
  total3=porsi*15000
  print(porsi," MAKAN 5 Rp.", total3)
  jenis3=("MAKAN 5")
 else:
  print("Pilihan menu tidak ada!!")
 makanan()
#fungsi minuman
 def minuman():
    global total2
    global gelas
    global jenis2
 print("\n****Menu Coffee****")
 print("1. COFFEE MILK WITH BROWN SUGAR = Rp.10000")
 print("2. COFFEE MILK WITH MACCHA      = Rp.13000")
 print("3. COFFE MUR SPESIAL            = Rp.20000")
 print("4. COFFEE ESSPRESO GAYO         = Rp.15000")
 print("5. TIDAK MEMESAN COFFEE         = Rp.0")
 nomor=int(input("MASUKKAN PILIHAN MINUMAN: "))
 gelas= int(input("Berapa Gelas: "))
 if nomor==1:
  total2=gelas*10000
  print(gelas," COFFE MILK WITH BROWN SUGAR Rp.", total2)
  jenis2=("COFFEE MILK WITH BROWN SUGAR")
 elif nomor==2:
  total2=gelas*13000
  print(gelas," COFFEE MILK WITH MACCHA Rp.", total2)
  jenis2=("COFFEE MILK WITH MACCHA")
 elif nomor==3:
  total2=gelas*20000
  print(gelas," COFFE MUR SPESIAL Rp.", total2)
  jenis2=("COFFE MUR SPESIAL")
 elif nomor==4:
  total2=gelas*15000
  print(gelas," COFFEE ESSPRESO GAYO Rp.", total2)
  jenis2=("COFFEE ESSPRESO GAYO")
 elif nomor==5:
  total2=gelas*0
  print(gelas," TIDAK MEMESAN COFFEE Rp.", total2)
  jenis2=("TIDAK MEMESAN COFFEE")
 else:
  print("Pilihan menu tidak ada!!")
 minuman()
 

 totalsemua=0
 totalsemua=total1+total2+total3
 print(f"\nTotal harus Dibayar : Rp.{totalsemua:,}")
 uang=int(input("uang tunai Pembeli  : "))
 kembalian=int(uang-totalsemua)
 print(f"Kembalian           : Rp.{kembalian:,}")
 
 print("\n")
 print("------------------------------------------------")
 print("\n^^^^^^^^^^^^^^^^^^ STRUK BOOKING ^^^^^^^^^^^^^^^")
 print(" ")
 print("Nama      : ",pemesan)
 print(f"Booking  :   {menginap} {jenis1} = {total1:,}")
 print(f"             {gelas} {jenis2} = {total2:,}")
 print(f"             {porsi} {jenis3} = {total3:,}")
 print(f"Tagihan  : Rp.{totalsemua:,}")
 print(f"Uang     : Rp.{uang:,}")
 print(f"Kembalian: Rp.{kembalian:,}")
 print("Tanggal Pemesanan : ",tanggal)
 print(f"~~~~~~ THANKYOU {pemesan} FOR YOUR ORDER ~~~~~")
 print(" ")
 print("------------------------------------------------")
 tanya=input("ingin lagi(y/n) ? ")
 if tanya =="n":
     break
print("\n<======PROGRAM TELAH SELESAI======>")