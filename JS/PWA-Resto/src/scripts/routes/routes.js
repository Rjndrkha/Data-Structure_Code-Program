import Home from '../views/pages/home';
import Detail from '../views/pages/detail';
import NotFound from '../views/pages/404';
import Like from '../views/pages/like';

const routes = {
  '/': Home,
  '/detail/:id': Detail,
  '/favorite': Like,
  '/404': NotFound,
};

export default routes;
