import { Alert, ScrollView, StyleSheet, Text, TouchableOpacity, View } from 'react-native'
import React from 'react'
import { FontAwesomeIcon } from '@fortawesome/react-native-fontawesome'
import { faArrowLeft, faArrowRight, faGreaterThan, faShoppingBag } from '@fortawesome/free-solid-svg-icons'
import CartItem from './CartItem'
import { useNavigation } from '@react-navigation/native'
import useCart from '../components/custom_hooks/cart'
export default function Cart() {
  const { cart,Subtotal} = useCart()
  const navigation = useNavigation()
  const isEmpty = Object.keys(Cart()).length === 0
  return (
    <View style={styles.container}>
      <View style={styles.header}>
        <TouchableOpacity onPress={() => navigation.goBack()}>
          <FontAwesomeIcon icon={faArrowLeft} size={20} color="black" />
        </TouchableOpacity>
        <Text style={{ fontSize: 20, fontWeight: "bold" }}>My Cart</Text>
        <FontAwesomeIcon icon={faShoppingBag} size={20} color="black" />
      </View>
      {!isEmpty ? <ScrollView
        contentContainerStyle={{ flexGrow: 1 }}
        showsVerticalScrollIndicator={false}
      >
        <View style={styles.items}>
          {
           Object.keys(cart).map((key) => {
              return <CartItem key={key} item={cart[key]} />
            }
           )
          }
        </View>
        <View style={{ flexGrow: 1, marginBottom: 10 }}>
          <View style={styles.voucher}>
            <Text style={styles.voucherText}>Promo/Student Codes or Voucher</Text>
            <FontAwesomeIcon style={{ marginTop: 5 }} icon={faGreaterThan} size={12} color="black" />
          </View>
          <View>
            <View>
              <View style={styles.totalTextContainer}>
                <Text style={styles.totalText}>Subtotal</Text>
                <View style={{ flexDirection: "row" }}>
                  <Text style={{ color: "orange" }}>$</Text>
                  <Text style={styles.priceText}>{Subtotal()}</Text>
                </View>
              </View>
              <View style={styles.totalTextContainer}>
                <Text style={styles.totalText}>Delivery</Text>
                <View style={{ flexDirection: "row" }}>
                  <Text style={{ color: "orange" }}>$</Text>
                  <Text style={styles.priceText}>10</Text>
                </View>
              </View>
            </View>
          </View>
          <View style={{ width: "100%", height: 10, borderBottomWidth: 1, borderColor: "grey", borderStyle: "dashed", marginBottom: 10 }}></View>
          <View style={styles.totalContainer}>
            <Text style={styles.totalText}>Total</Text>
            <View style={{ flexDirection: "row" }}>
              <Text style={{ color: "orange" }}>$</Text>
              <Text style={styles.priceText}>{Subtotal()}</Text>
            </View>
          </View>
          <TouchableOpacity style={styles.checkoutButton} onPress={() => navigation.navigate("CheckOut")}>
            <Text style={{ color: "white", fontSize: 15, fontWeight: "bold" }}>Checkout</Text>
          </TouchableOpacity>
        </View>

      </ScrollView> : <View style={{ flex: 1, justifyContent: "center", alignItems: "center" }}>
        <Text style={{ fontSize: 20, fontWeight: "bold" }}>Your cart is empty</Text>
        <TouchableOpacity style={{ backgroundColor: "black", width: "100%", height: 50, justifyContent: "center", alignItems: "center", borderRadius: 10, marginTop: 15 }} onPress={() => navigation.navigate("Home")}>
          <Text style={{ color: "white", fontSize: 15, fontWeight: "bold" }}>Continue Shopping</Text>
        </TouchableOpacity>
      </View>}

    </View>
  )
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: '#fff',
    padding: 20,
    paddingBottom: 0
  },
  header: {
    flexDirection: 'row',
    justifyContent: 'space-between',
    alignItems: 'center',
    // backgroundColor: '#fff',
    paddingBottom: 20,
    // borderBottomWidth: 1,
  },
  items: {
    flex: 1,
    marginBottom: 20
  },
  voucher: { justifyContent: "space-between", flexDirection: "row" },
  voucherText: { fontSize: 15, fontWeight: "bold" },
  totalTextContainer: { justifyContent: "space-between", flexDirection: "row", marginTop: 7 },
  totalText: { fontSize: 15, fontWeight: "bold", marginTop: 5, color: "grey" },
  priceText: { fontSize: 20, fontWeight: "bold" },
  totalContainer: { justifyContent: "space-between", flexDirection: "row", },
  checkoutButton: { backgroundColor: "black", width: "100%", height: 50, justifyContent: "center", alignItems: "center", borderRadius: 10, marginTop: 15 }
})