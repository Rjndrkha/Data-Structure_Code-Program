import { StyleSheet, Text, View,Image, TouchableOpacity } from 'react-native'
import React from 'react'
import { FontAwesomeIcon } from '@fortawesome/react-native-fontawesome'
import { faClose, faMinus, faPlus } from '@fortawesome/free-solid-svg-icons'
import useCart from '../components/custom_hooks/cart'
const items = {}

export default function CartItem({item}) {
  return (
    <View style={styles.itemContainer}>
        <View style={styles.item}>
            <Image source={item.image} style={styles.itemImage} />
            <View style={styles.itemDetails}>
                <Text style={styles.itemName}>{item.name}</Text>
                <Text style={styles.itemSize}>{item.size}</Text>
                <View style={{flexDirection:"row",alignItems:"center"}}>
                    <Text style={{color:"orange"}}>$</Text>
                <Text style={styles.itemPrice}>{item.price}</Text>
                </View>
                <View style={styles.itemQuantity}>
                    <View style={styles.itemQuantityButton}>
                        <TouchableOpacity style={styles.btn} onPress={() => decrementQuantity(item)}>
                            <FontAwesomeIcon icon={faMinus} size={10} color="black" />
                            </TouchableOpacity>
                        <Text style={styles.quantity}>1</Text>
                        <TouchableOpacity style={styles.btn} onPress={() => incrementQuantity(item)}>
                            <FontAwesomeIcon icon={faPlus} size={10} color="black" />
                            </TouchableOpacity>
                    </View>
                    <FontAwesomeIcon icon={faClose} size={15} color="grey" style={{marginTop:10}}/>
                </View>
            </View>
        </View>
    </View>
  )
}

const styles = StyleSheet.create({
    itemContainer: {
        flexGrow: 1,
        marginBottom: 20,
        width: '100%',
        // borderWidth: 1,
    },
    item: {
        flexGrow: 1,
        flexDirection: 'row',
        width: '100%',
    },
    itemImage: {
        width: 130,
        height: 170,
        resizeMode: 'contain',
        borderRadius: 10,
    },
    itemQuantityButton: {
        flexDirection: 'row',
        justifyContent: 'space-between',
        alignItems: 'center',
        marginTop: 10,
    },
    itemQuantity: {
        flexDirection: 'row',
        justifyContent: 'space-between',
        alignItems: 'center',
        marginTop: 10,
        width: "100%",
        // borderWidth: 1,
    },
    itemDetails: {
        flexGrow: 1,
        marginLeft: 10,
        width: '50%',
        // borderWidth: 1,
    },
    itemName: {
        fontSize: 20,
        fontWeight: 'bold',
        // borderWidth: 1,
        // flexGrow: 1,
    },
    itemSize: {
        marginTop: 5,
        fontSize: 15,
        color: 'grey',
    },
    itemPrice: {
        fontSize: 20,
        fontWeight: 'bold',
        marginTop: 10,
        
    },
    btn: {
        width: 20,
        height: 20,
        borderRadius: 5,
        borderWidth: 1,
        borderColor: 'black',
        justifyContent: 'center',
        alignItems: 'center',
    },
    quantity: {
        fontSize: 15,
        marginLeft: 10,
        marginRight: 10,
    }

})