import { Image, StyleSheet, Text, TouchableOpacity, View, Alert, FlatList } from 'react-native'
import { LinearGradient } from 'expo-linear-gradient'
import { FontAwesomeIcon } from '@fortawesome/react-native-fontawesome'
import { faGreaterThan } from '@fortawesome/free-solid-svg-icons'
import { faArrowLeft } from '@fortawesome/free-solid-svg-icons'
import { faStar } from '@fortawesome/free-solid-svg-icons'
import { faShoppingBag } from '@fortawesome/free-solid-svg-icons'
import React from 'react'
import useCart from '../components/custom_hooks/cart'

import { useNavigation } from '@react-navigation/native'
const HEIGHT = 350
const default_cart = {}
export default function Item(props) {
  const { cart, addToCart, getSize } = useCart()
  const navigation = useNavigation();
  const item = props.route.params.item
  const [currentIndex, setcurrentIndex] = React.useState(null)
  const [size, setSize] = React.useState(null)
  const handleAddToCart = () => {
    if (size != null && currentIndex != null) {
      // addToCart(item)
      // console.log(cart)
      Alert.alert("Success", "Item added to cart")
    }
    else {
      Alert.alert("Error", "Please select size")
    }
  }
  const sizes = ['S', 'M', 'L', 'XL']

  const handleSize = (size, index) => {
    setcurrentIndex(index === currentIndex ? null : index)
    setSize(size)
    getSize(size)
  }
  return (
    <View style={styles.container}>
      <View
        style={{
          padding: 20,
          width: "100%",
          justifyContent: 'space-between',
          flexDirection: 'row',
        }}>
        <TouchableOpacity
          onPress={() => { navigation.goBack() }}>
          <FontAwesomeIcon icon={faArrowLeft} size={26} color="black" />
        </TouchableOpacity>
        <TouchableOpacity
          onPress={() => { navigation.navigate("Cart") }}>
          <FontAwesomeIcon icon={faShoppingBag} size={26} color="black" />
        </TouchableOpacity>
      </View>
      <Image source={item.image} style={styles.img}></Image>
      <LinearGradient
        colors={['transparent', 'white', 'transparent']}
        style={{
          position: 'absolute',
          top: HEIGHT - 50,
          right: 0,
          width: '100%',
          height: 100,
        }}
      />
      <View style={styles.details}>
        <View style={
          {
            display: 'flex',
            flexDirection: 'row',
            justifyContent: 'space-between',
            alignItems: 'center',
            width: '100%',
          }
        }>
          <Text style={styles.title}>{item.name}</Text>
          <Text style={styles.price}>$<Text style={{ color: "black" }}>{item.price}</Text></Text>
        </View>
        <View style={styles.reviews}>
          <View style={styles.reviewBox}>
            <FontAwesomeIcon icon={faStar} size={15} color="orange" style={{ marginRight: 7 }} />
            <Text style={{ fontSize: 15, color: 'orange' }}>4.5</Text>
            <Text style={{ marginLeft: 2, fontSize: 12, color: 'grey', fontWeight: 'bold' }}> (2.6k+ reviews)</Text>
            <FontAwesomeIcon icon={faGreaterThan} size={10} color="grey" style={{ marginLeft: 7 }} />
          </View>
        </View>
        <View style={styles.size}>
          <Text style={styles.sizeText}>Select Size</Text>
          <View style={styles.sizeBox}>
            <FlatList
              data={sizes}
              horizontal
              showsHorizontalScrollIndicator={false}
              keyExtractor={(item, index) => index.toString()}

              renderItem={({ item, index }) => (
                <TouchableOpacity key={index} style={index === currentIndex ? styles.selected : styles.sizeSelect} activeOpacity={0.2} onPress={() => { handleSize(item, index) }}>
                  <Text style={index === currentIndex ? styles.selectedSize : styles.sizeText}>{item}</Text>
                </TouchableOpacity>
              )}
            />
          </View>

        </View>
        {/* <View style={styles.color}>
          <Text style={styles.colorText}>Select Color</Text>
          <View style={styles.colorBox}>
            <View style={[styles.colorSelect, { backgroundColor: "red" }]}></View>
            <View style={[styles.colorSelect, { backgroundColor: "purple" }]}></View>
            <View style={[styles.colorSelect, { backgroundColor: "pink" }]}></View>
            <View style={[styles.colorSelect, { backgroundColor: "blue" }]}></View>
            <View style={[styles.colorSelect, { backgroundColor: "blue" }]}></View>
            <View style={[styles.colorSelect, { backgroundColor: "blue" }]}></View>
            <View style={[styles.colorSelect, { backgroundColor: "blue" }]}></View>
          </View>
        </View> */}
        <TouchableOpacity style={styles.addToCart} activeOpacity={0.8} onPress={() => { handleAddToCart(item) }}>
          <Text style={{ color: "white" }}>Add to Cart</Text>
        </TouchableOpacity>
      </View>
    </View>
  )
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    alignItems: 'center',
    // justifyContent: 'center',
    margin: 0,
    padding: 0,
  },
  img: {
    width: "100%",
    height: HEIGHT,
    resizeMode: 'contain',
    position: 'absolute',
    top: 0,
    zIndex: -1,
    backgroundColor: 'white',
  },
  details: {
    display: 'flex',
    flexDirection: 'column',
    marginTop: HEIGHT - 70,
    width: '100%',
    padding: 20,
  },
  reviews: {
    marginTop: 5,
  },
  reviewText: {
    fontSize: 20,
    color: 'grey',
  },
  reviewBox: {
    display: 'flex',
    flexDirection: 'row',
    alignItems: 'center',
  },

  title: {
    fontSize: 18,
    //break line
    width: 200,
    fontWeight: 'bold',
    marginBottom: 10,
  },
  price: {
    fontSize: 30,
    fontWeight: 'bold',
    color: 'orange',
    marginTop: -10,
  },
  size: {
    display: 'flex',
    width: '100%',
    marginTop: 20,
  },
  selected: {
    backgroundColor: 'black',
    justifyContent: 'center',
    alignItems: 'center',
    borderWidth: 1,
    // borderColor: 'grey',
    paddingVertical: 10,
    paddingHorizontal: 15,
    margin: 7,
    borderRadius: 8,
  },
  sizeText: {
    fontSize: 15,
    fontWeight: 'bold',


  },
  selectedSize: {
    fontSize: 15,
    fontWeight: 'bold',
    color: 'white',
  },
  sizeBox: {
    display: 'flex',
    flexDirection: 'row',
    justifyContent: 'flex-start',
    alignItems: 'center',
    width: '100%',
    marginTop: 10,
  },
  sizeSelect: {
    justifyContent: 'center',
    alignItems: 'center',
    borderWidth: 1,
    borderColor: 'grey',
    paddingVertical: 10,
    paddingHorizontal: 15,
    margin: 7,
    borderRadius: 8,
  },
  color: {
    display: 'flex',
    width: '100%',
    marginTop: 10,
  },
  colorText: {
    fontSize: 15,
    fontWeight: 'bold',
    marginBottom: 10,
  },
  colorBox: {
    display: 'flex',
    flexDirection: 'row',
    justifyContent: 'flex-start',
    alignItems: 'center',

  },
  colorSelect: {
    justifyContent: 'center',
    alignItems: 'center',
    paddingVertical: 15,
    paddingHorizontal: 15,
    margin: 4,
    borderRadius: 8,
  },
  addToCart: {
    marginTop: 20,
    backgroundColor: 'black',
    paddingVertical: 15,
    paddingHorizontal: 15,
    borderRadius: 8,
    justifyContent: 'center',
    alignItems: 'center',
  },



})