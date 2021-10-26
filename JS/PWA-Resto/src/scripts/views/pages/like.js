import FavoriteRestaurantIdb from '../../data/favorite-restaurant-idb';
import FavoriteRestaurantSearchView from './liked-restaurants/favorite-restaurant-search-view';
import FavoriteRestaurantShowPresenter from './liked-restaurants/favorite-restaurant-show-presenter';
import FavoriteRestaurantSearchPresenter from './liked-restaurants/favorite-restaurant-search-presenter';

const view = new FavoriteRestaurantSearchView();

const Like = {
  async render() {
    return view.getTemplate();
  },

  async afterRender() {
    // let scriptElement = document.querySelector('script[src="https://use.fontawesome.com/b070c8f1df.js"]');

    // if (!scriptElement) {
    //   scriptElement = document.createElement('script');
    //   scriptElement.src = 'https://use.fontawesome.com/b070c8f1df.js';
    //   document.body.appendChild(scriptElement);
    // }

    new FavoriteRestaurantShowPresenter({ view, favoriteRestaurants: FavoriteRestaurantIdb });
    new FavoriteRestaurantSearchPresenter({ view, favoriteRestaurants: FavoriteRestaurantIdb });
  },
};

export default Like;
