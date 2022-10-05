import Home from './components/Home';
import { NavigationContainer } from '@react-navigation/native';
import { createNativeStackNavigator } from '@react-navigation/native-stack';
import SeeAll from './components/SeeAll';
import Item from './components/Item';
import Category from './components/Category';
import Cart from './components/Cart';
import {StyleSheet, Text, View} from 'react-native';
import CheckOut from './components/CheckOut';

const Stack = createNativeStackNavigator();

export default function App() {
  return (
    <NavigationContainer>
      
      <Stack.Navigator initialRouteName="Home" screenOptions={{
    headerShown: false,
  }}>
        <Stack.Screen name="Home" component={Home} />
        <Stack.Screen name="SeeAll" component={SeeAll} />
        <Stack.Screen name="Item" component={Item} />
        <Stack.Screen name="Category" component={Category} />
        <Stack.Screen name="Cart" component={Cart} />
        <Stack.Screen name="CheckOut" component={CheckOut} />
      </Stack.Navigator>
    </NavigationContainer>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: '#fff',
    alignItems: 'center',
    justifyContent: 'center',
  },
});
