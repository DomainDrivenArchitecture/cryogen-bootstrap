<div id="posts-by-tag">
    <div id="page-header">
        <h1>Posts Tagged &quot;{{name}}&quot;</h1>
    </div>
    <ul>
    {% for post in posts %}
        <li>
            <a href="{{post.uri}}">{{post.title}}</a>
        </li>
    {% endfor %}
    </ul>
</div>