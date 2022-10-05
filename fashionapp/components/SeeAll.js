import { FlatList, StyleSheet, Text, View, Image, TouchableOpacity } from 'react-native'
import React from 'react'
import { useNavigation } from '@react-navigation/native'
import { faAngleLeft } from '@fortawesome/free-solid-svg-icons'
import { FontAwesomeIcon } from '@fortawesome/react-native-fontawesome'
export default function SeeAll(props) {
  let data = props.route.params.data
  const category = props.route.params.category
  const navigation = useNavigation()
  const turncate = (str, n) => {
    return str?.length > n ? str.substr(0, n - 1) + "..." : str;
  }

  return (
    <View style={styles.SeeAllScreen}>
      <View style={styles.header}>
        <TouchableOpacity onPress={() => navigation.goBack()}>
          <FontAwesomeIcon
            icon={faAngleLeft}
            style={{ color: 'black' }}
            size={30}
          ></FontAwesomeIcon>
        </TouchableOpacity>
        <Text style={{
          fontSize: 35,
          fontWeight: 'bold',
        }}>{category}</Text>
      </View>
      <FlatList
        data={data}
        keyExtractor={id => data.id}
        renderItem={({ item }) => (
          <View style={{ flexGrow: 1 }}>
            <TouchableOpacity activeOpacity={0.8} onPress={() => navigation.navigate("Item", {
              item: item
            })}>
              <Image source={item.image} style={styles.categoryImage} />
            </TouchableOpacity>

            <View style={{ padding: 10 }}>
              <Text style={{ fontSize: 12, fontWeight: 'bold' }}>{turncate(item.name, 15)}</Text>
              <View style={{ flexDirection: "row" }}>
                <Text style={{ fontSize: 12, color: 'orange', fontWeight: 'bold' }}>$</Text>
                <Text style={{ fontSize: 15, fontWeight: 'bold' }}>{item.price}</Text>
              </View>
            </View>
          </View>
        )}
        numColumns={2}
        style={{ flex: 1 }}
      ></FlatList>

    </View>
  )
}

const styles = StyleSheet.create({
  SeeAllScreen: {
    marginTop: 0,
    padding: 20,
    flexGrow: 1
  },
  header: {
    flexDirection: 'column',
    marginBottom: 10,
    marginTop: 25
  },
  categoryImage: {
    width: 130,
    height: 200,
    resizeMode: 'contain',
    backgroundColor: 'white',
    margin: 7,
    borderRadius: 10
  }

})