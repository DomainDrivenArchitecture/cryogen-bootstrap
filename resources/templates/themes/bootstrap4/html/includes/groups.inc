{% for group in groups %}
    <h4>{{group.group}}</h4>
    <ul>
    {% for post in group.posts %}
    <li>
        {{post.date|date:"MMM dd"}} - <a href="{{post.uri}}">{{post.title}}</a>
    </li>
    {% endfor %}
    </ul>
{% endfor %}
    